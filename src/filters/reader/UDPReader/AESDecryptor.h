/*
 * (C) 2022 see Authors.txt
 *
 * This file is part of MPC-BE.
 *
 * MPC-BE is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-BE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef AESDECRYPTOR_HPP
#define AESDECRYPTOR_HPP

#include <bcrypt.h>
#include <memory>

class CAESDecryptor final
{
	struct HeapAllocDeleter {
		void operator()(LPVOID lpMem) {
			HeapFree(GetProcessHeap(), 0, lpMem);
		}
	};
	using uniqueHeapPtr = std::unique_ptr<UCHAR, HeapAllocDeleter>;

	bool m_bReadyDecrypt = {};
	BCRYPT_ALG_HANDLE m_hAesAlg = nullptr;

	uniqueHeapPtr m_pKeyObject;
	uniqueHeapPtr m_pIV;

	ULONG m_BlockLen = {};
	BCRYPT_KEY_HANDLE m_hKey = nullptr;

public:
	constexpr static size_t AESBLOCKSIZE = 16;

	CAESDecryptor();
	~CAESDecryptor();

	[[nodiscard]] bool SetKey(const BYTE* key, size_t keySize, const BYTE* iv, size_t ivSize);
	[[nodiscard]] bool Decrypt(const BYTE* encryptedData, size_t encryptedSize, BYTE* decryptedData, size_t& decryptedSize, bool bPadding);

	[[nodiscard]] bool IsInitialized() const { return m_hAesAlg != nullptr; }
	[[nodiscard]] bool IsReadyDecrypt() const { return m_bReadyDecrypt; }
};

#endif