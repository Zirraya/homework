#pragma once

class vec2 {
public:
	float x, y;
	vec2() {}
	vec2(float a, float b) : x(a), y(b) {}

};

class vec3 {
public:
	float x, y, z;
	// конструкторы
	vec3() {}
	vec3(float a, float b, float c) : x(a), y(b), z(c) {}
	vec3(vec2 v, float c) : vec3(v.x, v.y, c) {}
	// умножение векторов *= и *
	vec3& operator*=(const vec3& v) {
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return *this;

	}
	const vec3 operator*(const vec3& v) {
		return vec3(*this) *= v; // делаем временную копию текущего объекта,
		// которую домножаем на данный вектор,
			// и возвращаем ее как результат

	}

	// перегрузка []
	 float& operator[](int i) {
		 return ((float*)this)[i]; // ссылку на текущий объект рассматриваем как ссылку
		 // на нулевой элемент массива значений типа f
	}
};