# Hướng dẫn sử dụng problem-set

## Mục đích
Nhằm tạo sự tiện lợi cho các thành viên của câu lạc bộ ITMC trong việc tạo bài tập đăng lên web của câu lạc bộ. Problem-set là một thư mục chứa lời giải, đề bài, gợi ý và chương trình tạo testcase cho bài tập. Giúp rút ngắn thời gian tạo bài tập.

### Thư mục bao gồm
1. `solution.cpp` và `solution.py`: là file lời giải cho bài tập được viết bằng hai ngôn ngữ là `c++` và `python`.
2. `statement.md`: là file đề bài. Bạn có thể thay bằng `statement.docx` hoặc file đề bài tùy thích.
3. `editorial.md`: là file gợi ý. Bạn có thể thay bằng `editorial.docx` hoặc file gợi ý tùy thích.
4. `app.cpp`: là file bạn sẽ chỉnh sửa để tạo bộ testcase cho đề bài.
5. `info.json`: là file chứa các thông tin cần thiết của một bài tập. Bạn cần học một chút về JSON để sử dụng tối đa file này.
6. `setting.json`: là file chứa các cài đặt cho file `app.cpp`. Các cài đặt trong này sẽ được nói kỹ hơn bên dưới.
7. Thư mục `libraries` là nơi chứa các thư viện cần thiết cho file `app.cpp`. Bạn có thể thêm hoặc chỉnh sửa các thư viện này tùy theo ý thích.

## Hướng dẫn sử dụng

### Tạo đề bài

Như đã nói ở trên, bạn sẽ viết đề bài ở file `statement.md` nếu bạn biết sử dụng ngôn ngữ Markdown (mình khuyên bạn nên thử học qua). Nếu không bạn có thể viết đề bài bằng cách sử dụng các ứng dụng khác như Word.

Việc tạo đề bài ở đây sẽ giúp bạn tìm kiếm đề bài dễ dàng hơn, đỡ tốn công đi tìm ở các thư mục khác.

### Tạo gợi ý

Cũng như việc tạo đề bài, bạn sẽ viết gợi ý ở file `editorial.md` nếu bạn biết sử dụng ngôn ngữ Markdown. Nếu không bạn có thể viết gợi ý bằng cách sử dụng các ứng dụng khác như Word.

Việc tạo gợi ý ở đây sẽ giúp bạn tìm kiếm gợi ý dễ dàng hơn, đỡ tốn công đi tìm ở các thư mục khác.

### Tạo lời giải - viết code

Sau khi đã có đề bài và gợi ý, phần còn lại là viết lời giải, viết code. Ở đây có hai lựa chọn về ngôn ngữ là `c++` và `python`. Song việc viết lời giải ở ngôn ngữ `c++` là bắt buộc vì lời giải này sẽ được sử dụng để tạo các testcase (sẽ được nói ở sau). Trong tương lai mình sẽ mở rộng và nâng cấp hệ thống hoàn chỉnh hơn.

Kết thúc bước này, bạn đã có đề bài, gợi ý và lời giải cho một bài tập. Giờ bước cuối cùng là tạo các bộ test hay testcase cho đề bài.

### Tạo bộ test - testcase

***File cài đặt:***

Như đã nói ở trên, file `setting.json` là file chứa các cài đặt cho file `app.cpp`. Hiện tại, có $3$ cài đặt chính như sau:

1. Cài đặt số lượng testcase - `numberOfTestcase`: Bạn sẽ đưa ra số lượng testcase cho bộ test. Mặc định, mình để $40$ testcase cho một bộ test.
2. Cài đặt tạo file log cho bộ test - `createLog`: Một số bài tập cần có checker thì việc tạo bộ log cho bộ test là việc khá cần thiết. Đây là một chức năng thử nghiệm sẽ được hoàn thành trong tương lai. Hiện tại chức năng này chưa hoạt động được.
3. Cài đặt xóa các file dư thừa - `removeClusterFiles`: Sau quá trình tạo bộ test chương trình sẽ tạo ra các file dư thừa. Bạn có thể xóa thủ công các file này hoặc để chương trình xóa giúp bạn. Bạn có thể bật hoặc tắt chức năng này. Bạn để giá trị của thuộc tính `removeClusterFiles` là `true` để bật và `false` để tắt.

***File chương trình:***

Sau khi tùy chỉnh các cài đặt ở file `setting.json` bạn sẽ bắt đầu chỉnh sửa file `app.cpp` để tạo bộ test. Quá trình này cần vài bước như sau:

1. Viết đoạn code tạo dữ liệu vào cho bài toán (tạo Input cho bài toán).
    - Mỗi một bài toán lập trình đều có một dữ liệu vào, mô tả (giới hạn) của các dữ liệu này được viết cụ thể ở trong file đề bài. Bạn sẽ dựa vào đề bài để tạo các dữ liệu đầu vào này.
    - Trong file `app.cpp` có một hàm `makeInput()`. Tham số của hàm này gồm:
        - `const int testnumber`: cho biết thứ tự của test đang tạo.
        - `ofstream &cout`: luồng dữ liệu ra. Bạn không cần quá để ý tham số này nếu không hiểu quá rõ về `c++`.

    - Bạn sẽ viết một đoạn code nhỏ tạo các dữ liệu đầu vào cho bài toán của bạn. Nhớ rằng, mỗi bài toán có một tập dữ liệu đầu vào khác nhau! Đừng lười biếng copy code này sang code khác mà không hiểu ý nghĩa của chúng.
    - Vì hàm `makeInput()` là hàm `void` nên đừng trả về giá trị gì cả.
2. Viết đoạn code tạo dữ liệu ra (đáp án) tương ứng với dữ liệu đầu vào đã tạo ở bước $1$.
    - Ứng với mỗi dữ liệu đầu vào thì bạn cần một dữ liệu đầu ra (hay đáp án) tương ứng.
    - Trong file `app.cpp` có hàm `makeOutput()` với các tham số:
        - `ifstream &cin`: luồng đọc dữ liệu cho lời giải. Bạn không cần hiểu tham số này nếu không cần thiết.
        - `ofstream &cout`: luồng viết dữ liệu ra đáp án. Bạn không cần hiểu tham số này nếu không cần thiết.
    - Bạn có thể copy các dòng code trong hàm `int main()` ở file `solution.cpp` của bạn đã hoàn thành trước đó và `paste` vào hàm `makeInput()`. Các hàm phụ trợ trong file `solution.cpp` (nếu có) sẽ được copy và paste trên (trước) hàm `makeOutput()`. Bên cạnh việc copy lời giải, bạn có thể viết lại, nếu muốn.
3. Kiểm tra lỗi, dịch và chạy file `app.cpp`. Sau khi hoàn thành việc viết hai hàm `makeInput()` và `makeOutput()` ở trên. Bạn sẽ dịch và chạy file `app.cpp`. Chương trình sẽ tự động tạo bộ test cho bạn.

***Thu hoạch:***

Sau khi chương trình `app.exe` chạy xong, bạn sẽ thấy xuất hiện file `testcases.zip`. Đây là file nén chứa bộ test của bạn. Khi tạo bài tập trên web của câu lạc bộ bạn chỉ cần upload file này là xong.

## Lưu ý

Khi dịch và chạy file `app.cpp` nếu có lỗi hãy nhanh chóng thông báo cho mình để mình sửa kịp thời.
