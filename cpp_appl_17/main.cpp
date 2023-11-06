#include <iostream>


void fillMatrix(int** matrix, int numRows, int numCols) {
    int value = 1;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix[i][j] = value;
            value++;
        }
    }
}


void printMatrix(int** matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


void shiftRows(int** matrix, int numRows, int numCols, int shiftAmount, bool left) {
    int** tempMatrix = new int* [numRows];
    for (int i = 0; i < numRows; ++i) {
        tempMatrix[i] = new int[numCols];
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (left) {
                tempMatrix[i][(j - shiftAmount + numCols) % numCols] = matrix[i][j];
            }
            else {
                tempMatrix[i][(j + shiftAmount) % numCols] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix[i][j] = tempMatrix[i][j];
        }
    }

    for (int i = 0; i < numRows; ++i) {
        delete[] tempMatrix[i];
    }
    delete[] tempMatrix;
}

int main() {
    system("chcp 1251");
    system("cls");
    int numRows, numCols;
    std::cout << "¬вед≥ть к≥льк≥сть р€дк≥в: ";
    std::cin >> numRows;
    std::cout << "¬вед≥ть к≥льк≥сть стовпц≥в: ";
    std::cin >> numCols;

    int** matrix = new int* [numRows];
    for (int i = 0; i < numRows; ++i) {
        matrix[i] = new int[numCols];
    }

    fillMatrix(matrix, numRows, numCols);

    std::cout << "ѕочаткова матриц€:" << std::endl;
    printMatrix(matrix, numRows, numCols);

    int shiftAmount, shiftDirection;
    std::cout << "¬вед≥ть к≥льк≥сть зсув≥в: ";
    std::cin >> shiftAmount;
    std::cout << "¬вед≥ть напр€мок зсуву (0 - вл≥во, 1 - вправо): ";
    std::cin >> shiftDirection;

    bool left = (shiftDirection == 0);
    shiftRows(matrix, numRows, numCols, shiftAmount, left);

    std::cout << "ћатриц€ п≥сл€ цикл≥чного зсуву:" << std::endl;
    printMatrix(matrix, numRows, numCols);

   
    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}


