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

    int size,  rowID;
};

void fillInConstraints(const char *up, const char *down, const char *left, const char *right, int n, char **&result)
{
    int col = 2 * n * n;
    int up_count = 0, down_count = 0, left_count = 0, right_count = 0;

    for (int i = 0; i < n; ++i) {
        if(isalpha(up[i])){
            int letter = up[i] - 'A';
            result[i*n + letter][col + up_count] = '1';
            result[i*n + letter][col + up_count + 1] = '1';

            result[i*n + n - 1][col + up_count] = '1';

            result[n*n + i*n + letter][col + up_count + 1] = '1';
            up_count += 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        if(isalpha(down[i])){
            int letter = down[i] - 'A';
            result[n*n*n - n*n + i*n + letter][col + up_count + down_count] = '1';
            result[n*n*n - n*n + i*n + letter][col + up_count + down_count + 1] = '1';

            result[n*n*n - n*n + i*n + n - 1][col + up_count + down_count] = '1';

            result[n*n*n - 2*n*n + i*n + letter][col + up_count + down_count + 1] = '1';


            down_count += 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        if(isalpha(left[i])){
            int letter = left[i] - 'A';
            result[i*n*n + letter][col + up_count + down_count + left_count] = '1';
            result[i*n*n + letter][col + up_count + down_count + left_count + 1] = '1';

            result[i*n*n + n - 1][col + up_count + down_count + left_count] = '1';

            result[i*n*n + n + letter][col + up_count + down_count + left_count + 1] = '1';

            left_count += 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        if(isalpha(right[i])){
            int letter = right[i] - 'A';
            result[i*n*n + n*n - n + letter][col + up_count + down_count + left_count + right_count] = '1';
            result[i*n*n + n*n - n + letter][col + up_count + down_count + left_count + right_count + 1] = '1';

            result[i*n*n + n*n - 1][col + up_count + down_count + left_count + right_count] = '1';

            result[i*n*n + n*n - 2*n + letter][col + up_count + down_count + left_count + right_count + 1] = '1';

            right_count += 2;
        }
    }
}

void fillInUnique(int intercepter, int n, char **&result)
{
    for (int j = 0; j < n*n; ++j) {
        for (int i = 0; i < n; ++i) {
            result[j*n + i][intercepter + j] = '1';
        }
    }
}

void fillInColumns(int n, char **&result)
{
    for (int b_row_intercept = 0, b_col_intercept = 0; b_row_intercept < n * n * n; b_row_intercept += n * n, b_col_intercept += n) {
        for (int i = b_row_intercept; i < b_row_intercept + n * n; i += n) {
            for (int j = 0; j < n; ++j) {
                result[i + j][b_col_intercept + j] = '1';
            }
        }
    }
}

void fillRows(int n, char **&result)
{
    int len_columns = n * n, len_rows = n * n * n;
    int col = len_columns;
    for (int k = 0; k < len_rows; k += len_columns) {
        for (int i = 0; i < len_columns; ++i) {
            result[i + k][i + col] = '1';
        }
    }
}

int getNumber(int n, const char *up, const char *down, const char *left, const char *right)
{
    int constr_num = 0;
    for (int i = 0; i < n; ++i) {
        if(isalpha(up[i]))
            ++constr_num;
        if(isalpha(down[i]))
            ++constr_num;
        if(isalpha(left[i]))
            ++constr_num;
        if(isalpha(right[i]))
            ++constr_num;
    }
    return constr_num;
}


void deleteColumnAndRow(Node *column)
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

int getSolution(int k, Node *HeadNode, std::vector<Node *> &solution, int &res_size)
{
    if (HeadNode->right == HeadNode)
    {
        res_size = k;
        return k;
    }

    Node* Column = HeadNode->right;
    for (Node* temp = Column->right; temp != HeadNode; temp = temp->right)
        if (temp->size < Column->size)
            Column = temp;

    deleteColumnAndRow(Column);

    for (Node* temp = Column->down; temp != Column; temp = temp->down) {
        solution[k] = temp;

        for (Node* node = temp->right; node != temp; node = node->right)
            deleteColumnAndRow(node->head);

        getSolution(k + 1, HeadNode, solution, res_size);
        if(res_size != 0)
            return res_size;

        temp = solution[k];
        Column = temp->head;

        for (Node* node = temp->left; node != temp; node = node->left)
            getColAndRow(node->head);
    }

    getColAndRow(Column);
}

Node *createLinkList(char **matrix, int number_row, int number_column)
{
    Node* HeadNode;

    Node* header = new Node;

    header->up = header;
    header->size = -1;
    header->head = header;
    header->left = header;
    header->right = header;
    header->down = header;

    Node* temp = header;

    for (int i = 0; i < number_column; i++)
    {
        Node* newNode = new Node;

        newNode->size = 0;
        newNode->up = newNode;
        newNode->down = newNode;
        newNode->head = newNode;
        newNode->right = header;
        newNode->left = temp;
        temp->right = newNode;

        temp = newNode;
    }

    for (int i = 0; i < number_row; i++)
    {
        Node* top = header->right;
        Node* pprevious = nullptr;

        for (int j = 0; j < number_column; j++, top = top->right) {
            if (matrix[i][j] == '1') {
                Node* newNode = new Node;
                newNode->rowID = i;
                if (pprevious == nullptr)
                {
                    pprevious = newNode;
                    pprevious->right = newNode;
                }
                newNode->left = pprevious;
                newNode->right = pprevious->right;
                newNode->right->left = newNode;
                pprevious->right = newNode;

                newNode->down = top;
                newNode->up = top->up;
                top->up->down = newNode;

                newNode->head = top;
                top->size++;
                top->up = newNode;
                if (top->down == top)
                    top->down = newNode;
                pprevious = newNode;
            }
        }
    }

    HeadNode = header;
    return HeadNode;
}


void createMatrix(int n, char* up, char* down, char* left, char* right, char**& result, int& rows, int& columns)
{
    rows = n * n * n;
    int constr_num = getNumber(n, up, down, left, right);
    columns = 2 * (n * n + constr_num) + n * n;
    result = new char*[n * n * n];
    for (int i = 0; i < rows; ++i) {
        result[i] = new char[columns];
        for (int j = 0; j < columns; ++j) {
            result[i][j] = '0';
        }
    }
    fillInColumns(n, result);
    fillRows(n, result);


    fillInConstraints(up, down, left, right, n, result);
    fillInUnique(2*(n * n + constr_num), n, result);
}


void fillSymbolByRowID(int row_id, int n, char **result) {
    int row, column;
    char symbol;
    if((row_id + 1)%n == 0)
        symbol = '+';
    else
        symbol = 'A' + row_id % n;

    column = (row_id/n)%n;
    row = (row_id/(n*n))%n;

    result[row][column] = symbol;
}

//Основной метод решения задачи, параметры:
//n - размер исходной задачи и результата (NxN)
//up - доп. условия сверху, содержит буквы латинского алфавита и пробелы
//down - доп. условия снизу, содержит буквы латинского алфавита и пробелы
//left - доп. условия слева, содержит буквы латинского алфавита и пробелы
//up - доп. условия справа, содержит буквы латинского алфавита и пробелы
//result - матрица решения NxN, представлено как массив строчек, содержащих символы 'А-Z' и '+', для обозначения отсутствия буквы
void solve(char* up, char* down, char* left, char* right, char** result, int n)
{
    char** matrix = nullptr;
    int rows, columns;
    createMatrix(n, up, down, left, right, matrix, rows, columns);

    Node* HeadNode = createLinkList(matrix, rows, columns);
    vector<Node*> solution(rows * columns);

    int resultSize = 0;
    resultSize = getSolution(0, HeadNode, solution, resultSize);

    for (int i = 0; i < resultSize;  ++i)
    {
        int id_row = solution[i]->rowID;
        fillSymbolByRowID(id_row, n, result);
    }
}


int main()
{
    ReadWriter rw;
    //читаем параметры
    int n = rw.readInt();

    char* up = new char[n];
    char* down = new char[n];
    char* left = new char[n];
    char* right = new char[n];

    rw.readData(up, down, left, right, n);

    //Создаем массив, но не заполняем нулями, так как в методе все равно будет заполнена каждая ячейка
    char** result = new char*[n];
    for (int i=0; i< n; i++)
        result[i] = new char[n];
    //Основной алгоритм, возвращает результат как матрицу решения, память уже выделена под result
    solve(up, down, left, right, result, n);

    //выводим результат в файл
    rw.writeInt(n);
    rw.writeResult(result, n);

    //освобождаем память
    delete[] up;
    delete[] down;
    delete[] left;
    delete[] right;

    for (int i = 0; i < n; i++)
        delete[] result[i];
    delete[] result;

    return 0;
}