#pragma once

namespace Engine {
	/*
	Time

	Manages time by utilizing glfw functions.
	*/
	class Time final {
	private:
		static Time time;

	public:
		static void Tick();
		static float DeltaTime() { return static_cast<float>(time.dt); }

	private:
		double dt;
		double prev;

		Time();

	public:
		Time(const Time&) = delete;
		Time(Time&&) = delete;
		Time& operator=(const Time&) = delete;
		Time& operator=(Time&&) = delete;
		~Time();
	};
}