

# FLICKER BIRD

# Tác giả
Nguyễn Quang Cảnh - 22028200

INT2215_70 
UET

# Giới thiệu
* Game Flicker bird dựa trên game Flappy bird của  Nguyễn Hà Đông phát triển năm 2013.
* Bài tập lớn môn học Lập trình nâng cao - INT2215_70.

# Cách chạy game
## Bước 1: Cài đặt môi trường: Có thể cài đặt môi trường là Visual Studio Code phiên bản mới nhất và cài đặt những thiết lập cần thiết(C/C++ 17). 
Link: https://code.visualstudio.com/download
## Bước 2: Cài đặt các thư viện cần thiết bao gồm SDL2.framework, SDL2_image.framework, SDL2_mixer.framework, SDL2_ttf.framework.
Link: https://github.com/libsdl-org/SDL/releases/tag/release-2.30.6
## Bước 3: Tải game và chạy:
* Cách 1: Clone repo này về bằng lệnh "git clone + link.git của repo này" trên terminal máy bạn.
* Cách 2: Chọn Code -> Download Zip và giải nén.
* Mở file vừa giải nén, gõ "make" vào Terminal, sau đó gõ "./main" và chơi game.

# Mô tả trò chơi
* Đây là game thế hệ sau so với bản gốc ra đời năm 2013.
* Game chủ yếu dựa trên ý tưởng ban đầu của game gốc là cố gắng di chuyển chú chim bằng cách dùng chuột và bàn phím để giúp chú băng qua giữa các chướng ngại vật để đạt điểm số cao nhất có thể.
* Ngoài ra, game có 1 số cải tiến so với game gốc.
* Chú chim của chúng ta có thể nhấp nháy, đó là lý do game có tên là "Flicker Bird" - "Chú chim nhấp nháy".
* Hệ thống âm thanh.
* Hệ thống điểm cao để ghi lại điểm cao nhất của người chơi.
* Đổi background theo từng mức điểm, giúp người chơi cảm thâý bớt nhàm chán so với chỉ 1 hình nền.
* Tăng tốc chú chim theo từng mức điểm, giúp người chơi cảm thấy thú vị và thử thách hơn.
* Khi chú chim vượt quá màn hình(đâm xuống đất hoặc lên trời) chú chim sẽ không chết như bản gốc mà sẽ xuất hiện ở phần cạnh đối diện với nó.
* Chú chim sẽ có 2 mạng, khi va phải cột lần đầu tiên sẽ không chết và có âm thanh cảnh báo.
* Hệ thống huy chương theo từng mức điểm bạn đạt được.

## Các thành phần trong game
* Chú chim: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/blue-mid.png" alt="Bird" width="50" height="50">

* Cột: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/pipe.png" alt="Pipe" width="50" height="50">

* Điểm: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/7.png" alt="Score" width="50" height="50">

* Nút tạm dừng: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/pause.jpg" alt="Pause" width="50" height="50">

* Nút tiếp tục: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/resume.jpg" alt="Resume" width="50" height="50">

* Background: 

























<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/background-day.png" alt="Back1" width="200" height="400"> <img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/background-afternoon.png" alt="Back2" width="200" height="400"> <img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/background-night.png" alt="Back3" width="200" height="400">
* Mặt đất:
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/base.png" alt="Base" width="150" height="50">

* Màn hình kết quả: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/score.jpg" alt="Result" width="200" height="100">

* Huy chương đồng: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/dongmedal.PNG" alt="Bronze" width="50" height="50"> : Khi bạn đạt từ 0 đến 20 điểm.
* Huy chương bạc: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/bacmedal.PNG" alt="Silver" width="50" height="50">: Khi bạn đạt từ 21-30 điểm.
* Huy chương vàng: 
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/vangmedal.PNG" alt="gold" width="50" height="50">: Khi bạn đạt trên 30 điểm.


  
## Một số hình ảnh trong game
<img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/Demo1.png" alt="Ảnh mô tả" width="400" height="400">  <img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/Demo2.png" alt="Ảnh mô tả" width="400" height="400">  <img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/Demo3.png" alt="Ảnh mô tả" width="400" height="400">  <img src="https://github.com/croyce97/BTL_LTNC/blob/main/image/Demo4.png" alt="Ảnh mô tả" width="400" height="400">

## Các công cụ và kiến thức sử dụng để làm game
* Ngôn ngữ lập trình C/C++
* Thư viện SDL/SDL2
* Quản lý tài nguyên game
* Tạo giao diện người dùng
* Lập trình hướng đối tượng
* Cấu trúc dữ liệu và giải thuật

## Nguồn tham khảo
* Web tutorial SDL/SDL2: https://lazyfoo.net/tutorials/SDL/
* Chuỗi video youtuble về SDL/SDL2
* Game gốc ra đời năm 2013
* Đồ hoạ: https://www.cleanpng.com/
* Âm thanh: https://mixkit.co/
* Mã nguồn tham khảo: https://github.com/BlueHephaestus/flappy-bird-barebones

## Link demo game
Link: https://www.youtube.com/watch?v=U-UFjZ9YD0Q









