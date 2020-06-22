#include "ReadWriter.h"
#include <vector>

using namespace std;

struct Node
{
    Node *right;
    Node *up;
    Node *down;
    Node *left;

    Node *head;//указатель на заголовок столбца

    int size;
    int rowID;
};


Node *createLinkList(char **matrix, int number_row, int number_column)
{
    Node* HeadNode;
    Node* header = new Node;

    header->down = header;
    header->up = header;
    header->left = header;
    header->right = header;

    header->size = -1;
    header->head = header;

    Node* temp = header;

    for (int i = 0; i < number_column; i++)
    {
        Node* newNode = new Node;
        newNode->size = 0;
        newNode->right = header;
        newNode->left = temp;
        temp->right = newNode;
        newNode->up = newNode;
        newNode->down = newNode;
        newNode->head = newNode;
        temp = newNode;
    }

    for (int i = 0; i < number_row; i++)
    {
        Node* top = header->right;
        Node* previous = nullptr;

        for (int j = 0; j < number_column; j++, top = top->right) {
            if (matrix[i][j] == '1') {
                Node* newNode = new Node;
                newNode->rowID = i;
                if (previous == nullptr)
                {
                    previous = newNode;
                    previous->right = newNode;
                }
                newNode->left = previous;
                newNode->right = previous->right;
                newNode->right->left = newNode;
                previous->right = newNode;

                newNode->down = top;
                newNode->up = top->up;
                top->up->down = newNode;

                newNode->head = top;
                top->size++;
                top->up = newNode;
                if (top->down == top)
                    top->down = newNode;
                previous = newNode;
            }
        }
    }

    HeadNode = header;
    return HeadNode;
}

void getColAndRow(Node *column)
{
    for (Node* node = column->up; node != column; node = node->up)
    {
        for (Node* temp = node->left; temp != node; temp = temp->left)
        {
            temp->head->size++;
            temp->down->up = temp;
            temp->up->down = temp;
        }
    }

    column->left->right = column;
    column->right->left = column;
}


void deleteColAndRow(Node *column)
{
    column->left->right = column->right;
    column->right->left = column->left;

    for (Node* node = column->down; node != column; node = node->down)
    {
        for (Node* temp = node->right; temp != node; temp = temp->right)
        {
            temp->down->up = temp->up;
            temp->up->down = temp->down;
            temp->head->size--;
        }
    }
}
int findSolution(int k, Node *HeadNode, std::vector<Node *> &solution, int &result_size)
{
    if (HeadNode->right == HeadNode)
    {
        result_size = k;
        return k;
    }

    Node* Column = HeadNode->right;
    for (Node* temp = Column->right; temp != HeadNode; temp = temp->right)
        if (temp->size < Column->size)
            Column = temp;

    deleteColAndRow(Column);

    for (Node* temp = Column->down; temp != Column; temp = temp->down) {
        solution[k] = temp;

        for (Node* node = temp->right; node != temp; node = node->right)
            deleteColAndRow(node->head);

        findSolution(k + 1, HeadNode, solution, result_size);
        if(result_size != 0)
            return result_size;

        temp = solution[k];
        Column = temp->head;

        for (Node* node = temp->left; node != temp; node = node->left)
            getColAndRow(node->head);
    }

    getColAndRow(Column);
}

//Основной метод решения задачи, параметры:
//matrix - матрица NxM, представленная как N массивов по строкам, в каждом по M элементов '0' или '1'
//n, m - размеры матрицы
//result - массив для вывода решения, содержит строки из матрицы,
//для него надо выделить память здесь, передается по ссылке, чтобы можно было изменить указатель и получить это значение из main
//resultSize - количество строк в результате, передается по ссылке, чтобы можно было получить значение из main
void solve(char** matrix, int n, int m, char**& result, int& resultSize)
{
    //Можно создавать любые классы и методы для решения задачи
    //Советую разделить решение на логические блоки с комментариями

    Node* HeadNode = createLinkList(matrix, n, m);
    vector<Node*> solution(n*m);
    resultSize = 0;
    resultSize = findSolution(0, HeadNode, solution, resultSize);
    result = new char*[resultSize];
    string str_temp = "";

    for (int i = 0; i < resultSize;  ++i)
    {
        result[i] = new char[m];
        for (int j = 0; j < m; ++j)
        {
            result[i][j] = matrix[solution[i]->rowID][j];
            str_temp +=  matrix[solution[i]->rowID][j];
        }
    }
}


int main()
{
    ReadWriter rw;
    //читаем параметры
    int n, m;
    rw.readInts(n, m);

    char** matrix = new char*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new char[m];
    //читаем матрицу
    rw.readMatrix(matrix, n, m);

    //Память под result не выделяется здесь, так как неизвестно какое количество строк войдет в решение
    //Предлагается выделить память прямо в методе solve
    int resultSize = 0; //количество строк в решении
    char** result = nullptr;
    solve(matrix, n, m, result, resultSize);

    //выводим результат в файл
    rw.writeInts(resultSize, m);
    rw.writeMatrix(result, resultSize, m);

    //освобождаем память матрицы, которую выделяли здесь
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    //освобождаем память массива результата, которая здесь не выделялась...
    for (int i = 0; i < resultSize; i++)
        delete[] result[i];
    delete[] result;

    return 0;
}