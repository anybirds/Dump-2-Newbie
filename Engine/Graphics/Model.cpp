#include <map>

#include <Core/Debug.hpp>
#include <Graphics/Model.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace std;
using namespace Assimp;
using namespace Engine;

bool Model::Import(const char *model_path) {
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(model_path, aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenSmoothNormals);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
#ifdef DEBUG
		cout << '[' << __FUNCTION__ << ']' << " cannot open file: " << model_path << '\n';
#endif
		return false;
	}

	unsigned mcnt = scene->mNumMeshes; 
	for (unsigned midx = 0; midx < mcnt; midx++) {
		aiMesh *aimesh = scene->mMeshes[midx];
		unsigned base;

		unsigned acnt = 3;
		unsigned *attrib = new unsigned[acnt];
		if (aimesh->HasPositions()) {
			attrib[0] = 3;
		}
		if (aimesh->HasNormals()) {
			attrib[1] = 3;
		}
		if (aimesh->HasTextureCoords(0)) {
			attrib[2] = 2;
		}
		unsigned asize = 0; // number of floats for each vertex 
		for (unsigned i = 0; i < acnt; i++) {
			asize += attrib[i];
		}

		unsigned vcnt = aimesh->mNumVertices;
		float *vert = new float[vcnt * asize];
		base = 0;
		for (unsigned i = 0; i < aimesh->mNumVertices; i++) {
			if (aimesh->HasPositions()) {
				vert[base] = aimesh->mVertices[i].x;
				vert[base + 1] = aimesh->mVertices[i].y;
				vert[base + 2] = aimesh->mVertices[i].z;
				base += 3;
			}
			if (aimesh->HasNormals()) {
				vert[base] = aimesh->mNormals[i].x;
				vert[base + 1] = aimesh->mNormals[i].y;
				vert[base + 2] = aimesh->mNormals[i].z;
				base += 3;
			}
			if (aimesh->HasTextureCoords(0)) { // texture coordinate set 0
				vert[base] = aimesh->mTextureCoords[0][i].x;
				vert[base + 1] = aimesh->mTextureCoords[0][i].y;
				base += 2;
			}
		}

		unsigned icnt = aimesh->mNumFaces * 3;
		unsigned *idx = new unsigned[icnt];
		base = 0;
		for (unsigned i = 0; i < aimesh->mNumFaces; i++) {
			idx[base] = aimesh->mFaces[i].mIndices[0];
			idx[base + 1] = aimesh->mFaces[i].mIndices[1];
			idx[base + 2] = aimesh->mFaces[i].mIndices[2];
			base += 3;
		}

		Mesh *mesh = new Mesh(aimesh->mName.C_Str(), vert, vcnt, attrib, acnt, idx, icnt);
		delete vert;
		delete attrib;
		delete idx;
	}

	return true;
}