# Simple Blockchain Implementation

Educational project of a **simple blockchain implementation** in **C++**, focused on understanding the cryptographic and mathematical foundations of blockchain systems, including proof-of-work mining and entropy generation.

---

## Objective

The goal of this project is to study and implement, step by step, the core components of a blockchain, including:

- **Cryptographically secure entropy generation**
- **Block structure** with hash, timestamp and data
- **Proof-of-work (PoW) mining algorithm**
- **Mining difficulty validation**
- **SHA-256 hash calculation** using OpenSSL
- **Private key validation** with secp256k1 elliptic curve constraints

The focus is on **learning and understanding** the fundamental concepts of blockchain technology.

---

## Features

### Proof of Work (PoW)
The mining algorithm implements the proof-of-work concept:
- The miner must find a nonce that, when combined with the block data, generates a hash starting with N zeros
- The higher the difficulty, the more zeros are required, exponentially increasing the computational work

### Entropy Validation
The generated entropy is validated according to the secp256k1 elliptic curve standards (used in Bitcoin):
- Must be exactly 32 bytes
- Must be in the range [1, N-1] where N is the curve order
- Ensures that private keys are valid

### Hash Chaining
Each block stores the hash of the previous block (`last_hash`), creating an immutable chain of blocks.

---

## Requirements

- **C++ Compiler**: g++ with C++17 or higher support
- **OpenSSL**: Library for cryptographic functions (SHA-256)

### Installing OpenSSL (Ubuntu/Debian)

```bash
sudo apt-get install libssl-dev
```

---

## Compilation and Execution

### Compile

```bash
g++ -Wall -Wextra -g3 main.cpp -o output/main -lssl -lcrypto
```

### Run

```bash
./output/main
```

### Expected Output

The program demonstrates:
1. Generation of 32 bytes of cryptographically valid entropy
2. Mining of a block with difficulty 6 (hash must start with 6 zeros)
3. Display of the resulting hash and the nonce found

Example output:
```
Generated Entropy: a3f5c8e9d2b1...
Block Hash: 0000008a3c5e...
Mined Nonce: 1847203
```

---

## Limitations and Warnings

⚠️ **This project is purely educational and should NOT be used for:**
- Storing or processing real cryptocurrencies
- Production systems
- Applications that require robust cryptographic security

**Known limitations:**
- Use of `std::random_device` may not be cryptographically secure on all platforms
- Absence of complete blockchain validation
- Lack of P2P network implementation
- No data persistence
- Incomplete elliptic curve implementation

---

## License

This project is open source for educational purposes.

---

## References

- [Bitcoin Whitepaper - Satoshi Nakamoto](https://bitcoin.org/bitcoin.pdf)
- [Mastering Bitcoin - Andreas M. Antonopoulos](https://github.com/bitcoinbook/bitcoinbook)
- [OpenSSL Documentation](https://www.openssl.org/docs/)
- [secp256k1 Curve Parameters](https://en.bitcoin.it/wiki/Secp256k1)
