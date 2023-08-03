# Dokumentasi Tugas Akhir Grafika Komputer 
Projek tugas akhir mata kuliah Grafika Komputer dengan dosen pengampu bapak Ahmad Azhari, S.Kom, M.Eng. 

**Header yang digunakan :**
- windowh.h
- glut.h ( dipakai untuk mengaktifkan sintaks fungsi yang berawalan "gl", contoh : glPushMatrix(), glRotatef(), dan lain lain )
- cmath ( dipakai untuk mengaktifkan sintaks cos, sin, tan, dan perhitungan matematika lain.)


**Output tampilan :** 
- objek 3D bus biru dengan detail jendela, lampu, roda, dan pintu.
- objek bus berjalan di atas jalan raya yang memiliki trotoar, kemudian dikelilingi kota kota dan pohon pohon

**IDE yang digunakan :** Dev C++

Cara Menjalankan Program :
- Buat projek baru pada Dev C++,
- masukan nama project(nama bebas),
- pilih bahasa C++ project, 
- pilih jenis Console Application
- Project baru telah dibuat
- pilih Project pada taskbar
- pilih Project Options
- pilh tab Parameters
- masukan linker dengan sintaks berikut :
  [-lopengl32
  -lfreeglut
  -lglu32 ]


