#pragma once

#include <cglm/cglm.h>
#include <cglm/mat4.h>

typedef struct {
		vec3 position;
		float rotation;

		mat4 projection_matrix;
		mat4 view_matrix;
		mat4 view_projection_matrix;


} Camera;

Camera CreateCamera(float left, float right, float bottom, float top) {
		Camera cam;

		glm_ortho(left, right, bottom, top, -1.0f, 1.0f, cam.projection_matrix);
		glm_mat4_identity(cam.view_matrix);

		glm_mat4_mul(cam.projection_matrix, cam.view_matrix, cam.view_projection_matrix);

		return cam;
}

void SetProjection(Camera *cam, float left, float right, float bottom, float top) {
		glm_ortho(left, right, bottom, top, -1.0f, 1.0f, cam->projection_matrix);
}
		

