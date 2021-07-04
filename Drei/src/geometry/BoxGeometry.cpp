#include "BoxGeometry.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

#include <vector>
#include <iostream>

void BoxGeometry::draw() {
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, 0);
}

BoxGeometry::BoxGeometry() : BoxGeometry(1,1,1) {}

BoxGeometry::BoxGeometry(float width, float height, float depth) {
    float h = height / 2;
    float w = width / 2;
    float d = depth / 2;

    unsigned int indices[] = {
        // front
        0, 1, 2,
        2, 3, 0,
        // back
        5, 4, 7,
        7, 6, 5,
        // floor
        9, 8, 11,
        11, 10, 9,
        // roof
        12, 13, 14,
        14, 15, 12,
        // right
        16, 17, 18,
        18, 19, 16,
        // left
        21, 20, 23,
        23, 22, 21
    };

    float vertices[144] = {
        // front 
        -w,-h,  d, 0, 0, 1, // bottom left
        w, -h,  d, 0, 0, 1, // bottom right
        w,  h,  d, 0, 0, 1, // top right
        -w, h,  d, 0, 0, 1, // top left
        // back
        -w,-h, -d, 0, 0, -1,
        w, -h, -d, 0, 0, -1,
        w,  h, -d, 0, 0, -1,
        -w, h, -d, 0, 0, -1,
        // floor
        -w,-h,  d, 0, -1, 0, // front left
        w, -h,  d, 0, -1, 0, // front right
        w, -h, -d, 0, -1, 0, // back right
        -w,-h, -d, 0, -1, 0, // back left
        // roof
        -w,h,  d, 0, 1, 0, // front left
        w, h,  d, 0, 1, 0, // front right
        w, h, -d, 0, 1, 0, // back right
        -w,h, -d, 0, 1, 0, // back left
        // right
        w, -h,  d, 1, 0, 0, // front bottom
        w, -h, -d, 1, 0, 0, // back bottom
        w,  h, -d, 1, 0, 0, // back top
        w,  h,  d, 1, 0, 0, // front top
        // left
        -w, -h,  d, -1, 0, 0, // front bottom
        -w, -h, -d, -1, 0, 0, // back bottom
        -w,  h, -d, -1, 0, 0, // back top
        -w,  h,  d, -1, 0, 0, // front top
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
