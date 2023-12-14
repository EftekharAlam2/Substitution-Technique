#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
  if (b == 0)
  return a;
  else
  return gcd(b, a % b);
}

int modInverse(int a, int m) {
  int m0 = m;
  int y = 0, x = 1;
  if (m == 1)
  return 0;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0)
  x += m0;
  return x;
}

void generateKeys(int p, int q, int *e, int *d, int *n) {
  int phi = (p - 1) * (q - 1);
  *n = p * q;

  for (*e = 2; *e < phi; ++(*e)) {
    if (gcd(*e, phi) == 1)
    break;
  }

  *d = modInverse(*e, phi);
}

int encrypt(int msg, int e, int n) {
  int c = 1;
  for (int i = 0; i < e; ++i) {
    c = (c * msg) % n;
  }
  return c;
}

int decrypt(int msg, int d, int n) {
  int m = 1;
  for (int i = 0; i < d; ++i) {
    m = (m * msg) % n;
  }
  return m;
}

int main() {
  int p, q, e, d, n;
  int plaintext, ciphertext, decryptedtext;

  printf("Enter two prime numbers (p and q): ");
  scanf("%d %d", &p, &q);
  generateKeys(p, q, &e, &d, &n);

  printf("Public Key (e, n): (%d, %d)\n", e, n);
  printf("Private Key (d, n): (%d, %d)\n", d, n);

  printf("Enter a message to encrypt: ");
  scanf("%d", &plaintext);

  ciphertext = encrypt(plaintext, e, n);
  printf("Encrypted message: %d\n", ciphertext);

  decryptedtext = decrypt(ciphertext, d, n);
  printf("Decrypted message: %d\n", decryptedtext);
  
  return 0;
}