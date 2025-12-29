# Simple_Bitcoin_Wallet

Educational project of a **simple Bitcoin wallet**, implemented in **C++**, focused on understanding the **cryptographic and mathematical foundations** of Bitcoin, avoiding ready-made abstractions whenever possible.

⚠️ **This project must NOT be used to store real Bitcoin.**

---

## Objective

The goal of this project is to study and implement, step by step, the core components of a Bitcoin wallet, including:

- **Private key generation**
- Mathematical constraints of the **secp256k1 elliptic curve**
- Bitcoin encodings (WIF, Base58Check)
- **Public key derivation**
- **Bitcoin address generation**
- Internal mechanics of how a wallet works

The focus is **learning and understanding**, not production-grade security.

---

## Current Project Status

At the current stage, the project implements:

- Generation of **256-bit entropy (32 bytes)**
- Private key validation ensuring that:
  - The key size is exactly **32 bytes**
  - The key is **not zero**
  - The key is **smaller than the secp256k1 curve order**

Key generation is repeated until a mathematically valid private key is obtained.

---

## Mathematical Background

In Bitcoin, a private key `k` must satisfy:

