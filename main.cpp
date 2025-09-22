#include <bits/stdc++.h>
using namespace std;

struct List {
    int arr[1000];
    int sizee;

    List() {
        sizee = 0;
    }

    bool addh(int x) { // thêm vào cuối - O(1)
        if (sizee == 1000) return false;
        arr[sizee++] = x;
        return true;
    }

    bool addt(int x) { // thêm vào đầu - O(N)
        if (sizee == 1000) return false;
        for (int i = sizee; i > 0; i--)
            arr[i] = arr[i - 1];
        arr[0] = x;
        sizee++;
        return true;
    }

    bool addi(int x, int pos) { // thêm vào vị trí bất kỳ - O(N)
        if (sizee == 1000 || pos < 0 || pos > sizee) return false;
        for (int i = sizee; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = x;
        sizee++;
        return true;
    }

    bool poph() { // xóa đầu - O(N)
        if (sizee == 0) return false;
        for (int i = 0; i < sizee - 1; i++)
            arr[i] = arr[i + 1];
        sizee--;
        return true;
    }

    bool popt() { // xóa cuối - O(1)
        if (sizee == 0) return false;
        sizee--;
        return true;
    }

    bool popi(int pos) { // xóa tại pos - O(N)
        if (pos < 0 || pos >= sizee) return false;
        for (int i = pos; i < sizee - 1; i++)
            arr[i] = arr[i + 1];
        sizee--;
        return true;
    }

    int get(int pos) { // lấy phần tử tại pos - O(1)
        if (pos < 0 || pos >= sizee) return -1;
        return arr[pos];
    }

    void print() { // in xuôi - O(N)
        for (int i = 0; i < sizee; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void printReverse() { // in ngược - O(N)
        for (int i = sizee - 1; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    List l;
    l.addh(10);
    l.addh(20);
    l.addt(2);
    l.addi(15, 2);

    cout << "Danh sach sau khi them: ";
    l.print();

    l.poph();
    cout << "Sau khi xoa dau: ";
    l.print();

    l.popt();
    cout << "Sau khi xoa cuoi: ";
    l.print();

    l.addh(30);
    l.addh(40);
    cout << "In nguoc: ";
    l.printReverse();

    return 0;
}
