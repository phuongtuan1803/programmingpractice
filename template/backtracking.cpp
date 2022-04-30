//  Liệt kê các tập con k phần tử 

void try(int i) {
    for (int v = x[i - 1] + 1; v <= n - k + i; ++v) {
        x[i] = v;
        if (i == k)
            print(x);
        else
            try(i+1);
    }
}

// Liệt kê các chỉnh hợp không lặp chập k

void try(int i) {
    for (int v = 1; v <= n; ++v) {
        if (c[v]) { //giá trị v đang tự do
            x[i] = v;
            if (i == k) // Nếu đã chọn đến bước thứ k thì chỉ cần in ra
                print(x);
            else {
                c[v] = false;  // đánh dấu giá trị v đã được lựa chọn
                try(i+1);
                c[v] = true;   // bỏ đánh dấu, giá trị v trở thành tự do vì x[i] sắp được thử một các chọn khác.
            }
        }
    }
}

// Liệt kê các hoán vị

void try(int i) {
    for (int v = 1; v <= n; ++v) {
        if (c[v]) { //giá trị v đang tự do
            x[i] = v;
            if (i == n) // Nếu đã chọn đến bước thứ n thì chỉ cần in ra
                print(x);
            else {
                c[v] = false;  // đánh dấu giá trị v đã được lựa chọn
                try(i+1);
                c[v] = true;   // bỏ đánh dấu, giá trị v trở thành tự do vì x[i] sắp được thử một các chọn khác.
            }
        }
    }
}


// Branch and Bound

void init() {
    Khởi tạo một cầu hình bất kỳ BEST_CONFIG;
}
 
void try(int i) {
    for (v : {tập giá trị có thể cho x[i]) {
        x[i] = v;
        if (việc thử còn hy vọng để tìm ra cấu hình tốt hơn BEST_CONFIG) {
            if (i == k) { //Nếu i là phần tử cuối cùng trong cấu hình
                cập nhật BEST_CONFIG;
            }
            else {
                mark[v] = true; //Ghi nhận việc x[i] nhận giá trị V nếu cần
                try(i+1);
                mark[v] = false; //Bỏ ghi nhận việc thử cho x[i] nếu cần
            }
        }
    }
}
/*
     Bai toan tim Max
        Xac dinh can tren
        Sap xep giam dan
*/ 
