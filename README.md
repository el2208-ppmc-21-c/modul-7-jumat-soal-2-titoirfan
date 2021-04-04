# Modul 7 Jumat Soal 2: Stacks and Queues

### Instruksi
Bacalah dokumen ini serta naskah soal yang terdapat pada *repo* ini dengan seksama.

Diinginkan sebuah program `soal-01.c` dan `soal-02.c` yang memenuhi ketentuan pada naskah soal. 

Silakan sesuaikan isi `soal-01.c` dan `soal-02.c` hingga memenuhi ketentuan pada naskah soal, kemudian lakukan *commit* dan *push* modifikasi anda ke branch `origin/master`.

#### Hint
Anda dapat:
1. Meng-*clone* *repo* ini, mengedit isi *source code* secara *offline*, kemudian melakukan *commit* dan *push* ke `origin/master`, atau
2. Mengunduh *repo* ini, mengedit isi *source code* secara *offline*, kemudian mengunggah *file* yang anda ubah via web, atau
3. Secara langsung mengedit isi *source code* di situs web GitHub dan melakukan *commit*.

### Kompilasi
*Autograder* telah diatur untuk melakukan kompilasi dengan perintah berikut:

```bash
# Soal pertama
make soal-01

# Soal kedua
make soal-02
```

Karenanya, pastikan bahwa isi Makefile dapat mengkompilasi kode anda dengan benar. Perhatikan bahwa *autograder* GitHub menggunakan *compiler* `gcc` dan bekerja dalam lingkungan Linux, sehingga anda perlu menyesuaikan isi Makefile dengan kebutuhan *autograder* (i.e. tidak menggunakan ekstensi apapun (*file binary*) alih-alih ekstensi `.exe` untuk *file executable*, mencantumkan secara eksplisit *flag linker* ke *library* ketika kompilasi, etc.)

### Perintah Run
*Autograder* telah diatur untuk menjalankan program dengan perintah berikut:

```bash
# Soal pertama
./soal-01

# Soal kedua
./soal-02
```
Karenanya, pastikan bahwa perintah kompilasi yang telah dijelaskan di atas akan menghasilkan *file executable* dengan nama `soal-01` dan `soal-02` untuk masing-masing soal. Perhatikan bahwa *file executable* tidak memiliki ekstensi `.exe`.
