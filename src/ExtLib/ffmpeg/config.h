#ifndef FFMPEG_CONFIG_H
#define FFMPEG_CONFIG_H

#define SWS_MAX_FILTER_SIZE 256
#ifdef __GNUC__
	#define HAVE_MMX2 HAVE_MMXEXT
	#define ARCH_X86 1
	#define HAVE_INLINE_ASM 1
	#define HAVE_AESNI 1
	#define HAVE_AMD3DNOW 1
	#define HAVE_AMD3DNOWEXT 1
	#define HAVE_AVX 1
	#define HAVE_AVX2 1
	#define HAVE_AVX512 1
	#define HAVE_AVX512ICL 1
	#define HAVE_FMA3 1
	#define HAVE_FMA4 1
	#define HAVE_MMX 1
	#define HAVE_MMXEXT 1
	#define HAVE_SSE 1
	#define HAVE_SSE2 1
	#define HAVE_SSE3 1
	#define HAVE_SSE4 1
	#define HAVE_SSE42 1
	#define HAVE_SSSE3 1
	#define HAVE_XOP 1
	#define HAVE_CPUNOP 0
	#define HAVE_I686 1
	#define HAVE_AESNI_EXTERNAL 1
	#define HAVE_AMD3DNOW_EXTERNAL 1
	#define HAVE_AMD3DNOWEXT_EXTERNAL 1
	#define HAVE_AVX_EXTERNAL 1
	#define HAVE_AVX2_EXTERNAL 1
	#define HAVE_AVX512_EXTERNAL 0
	#define HAVE_AVX512ICL_EXTERNAL 0
	#define HAVE_FMA3_EXTERNAL 1
	#define HAVE_FMA4_EXTERNAL 1
	#define HAVE_MMX_EXTERNAL 1
	#define HAVE_MMXEXT_EXTERNAL 1
	#define HAVE_SSE_EXTERNAL 1
	#define HAVE_SSE2_EXTERNAL 1
	#define HAVE_SSE3_EXTERNAL 1
	#define HAVE_SSE4_EXTERNAL 1
	#define HAVE_SSE42_EXTERNAL 1
	#define HAVE_SSSE3_EXTERNAL 1
	#define HAVE_XOP_EXTERNAL 1
	#define HAVE_CPUNOP_EXTERNAL 0
	#define HAVE_I686_EXTERNAL 0
	#define HAVE_AESNI_INLINE 1
	#define HAVE_AMD3DNOW_INLINE 1
	#define HAVE_AMD3DNOWEXT_INLINE 1
	#define HAVE_AVX_INLINE 1
	#define HAVE_AVX2_INLINE 1
	#define HAVE_AVX512_INLINE 1
	#define HAVE_AVX512ICL_INLINE 1
	#define HAVE_FMA3_INLINE 1
	#define HAVE_FMA4_INLINE 1
	#define HAVE_MMX_INLINE 1
	#define HAVE_MMXEXT_INLINE 1
	#define HAVE_SSE_INLINE 1
	#define HAVE_SSE2_INLINE 1
	#define HAVE_SSE3_INLINE 1
	#define HAVE_SSE4_INLINE 1
	#define HAVE_SSE42_INLINE 1
	#define HAVE_SSSE3_INLINE 1
	#define HAVE_XOP_INLINE 1
	#define HAVE_CPUNOP_INLINE 0
	#define HAVE_I686_INLINE 0

	#ifdef ARCH_X86_64
		#define BROKEN_RELOCATIONS 1
		#define ARCH_X86_32 0
		#define ARCH_X86_64 1
		#define HAVE_FAST_64BIT 1
		#define HAVE_FAST_CMOV 1
		#define HAVE_MM_EMPTY 1
		#define HAVE_XMM_CLOBBERS 1
		#define CONFIG_PIC 1
	#else
		#define ARCH_X86_32 1
		#define ARCH_X86_64 0
		#define HAVE_FAST_64BIT 0
		#define HAVE_FAST_CMOV 0
		#define HAVE_MM_EMPTY 0
		#define HAVE_XMM_CLOBBERS 0
		#define CONFIG_PIC 0
	#endif

	#ifndef av_restrict
	#define av_restrict restrict
	#endif
#else
	#define HAVE_INLINE_ASM 0
	#define HAVE_AESNI 0
	#define HAVE_AMD3DNOW 0
	#define HAVE_AMD3DNOWEXT 0
	#define HAVE_AVX 0
	#define HAVE_AVX2 0
	#define HAVE_AVX512 0
	#define HAVE_AVX512ICL 0
	#define HAVE_FMA3 0
	#define HAVE_FMA4 0
	#define HAVE_MMX 0
	#define HAVE_MMXEXT 0
	#define HAVE_SSE 0
	#define HAVE_SSE2 0
	#define HAVE_SSE3 0
	#define HAVE_SSE4 0
	#define HAVE_SSE42 0
	#define HAVE_SSSE3 0
	#define HAVE_XOP 0
	#define HAVE_CPUNOP 0
	#define HAVE_I686 0
	#define HAVE_AESNI_EXTERNAL 0
	#define HAVE_AMD3DNOW_EXTERNAL 0
	#define HAVE_AMD3DNOWEXT_EXTERNAL 0
	#define HAVE_AVX_EXTERNAL 0
	#define HAVE_AVX2_EXTERNAL 0
	#define HAVE_AVX512_EXTERNAL 0
	#define HAVE_AVX512ICL_EXTERNAL 0
	#define HAVE_FMA3_EXTERNAL 0
	#define HAVE_FMA4_EXTERNAL 0
	#define HAVE_MMX_EXTERNAL 0
	#define HAVE_MMXEXT_EXTERNAL 0
	#define HAVE_SSE_EXTERNAL 0
	#define HAVE_SSE2_EXTERNAL 0
	#define HAVE_SSE3_EXTERNAL 0
	#define HAVE_SSE4_EXTERNAL 0
	#define HAVE_SSE42_EXTERNAL 0
	#define HAVE_SSSE3_EXTERNAL 0
	#define HAVE_XOP_EXTERNAL 0
	#define HAVE_CPUNOP_EXTERNAL 0
	#define HAVE_I686_EXTERNAL 0
	#define HAVE_AESNI_INLINE 0
	#define HAVE_AMD3DNOW_INLINE 0
	#define HAVE_AMD3DNOWEXT_INLINE 0
	#define HAVE_AVX_INLINE 0
	#define HAVE_AVX2_INLINE 0
	#define HAVE_AVX512_INLINE 0
	#define HAVE_AVX512ICL_INLINE 0
	#define HAVE_FMA3_INLINE 0
	#define HAVE_FMA4_INLINE 0
	#define HAVE_MMX_INLINE 0
	#define HAVE_MMXEXT_INLINE 0
	#define HAVE_SSE_INLINE 0
	#define HAVE_SSE2_INLINE 0
	#define HAVE_SSE3_INLINE 0
	#define HAVE_SSE4_INLINE 0
	#define HAVE_SSE42_INLINE 0
	#define HAVE_SSSE3_INLINE 0
	#define HAVE_XOP_INLINE 0
	#define HAVE_CPUNOP_INLINE 0
	#define HAVE_I686_INLINE 0
	#define ARCH_X86 0
	#define ARCH_X86_32 0
	#define ARCH_X86_64 0
	#define HAVE_FAST_64BIT 0
	#define HAVE_FAST_CMOV 0
	#define HAVE_MM_EMPTY 0
	#define HAVE_XMM_CLOBBERS 0
	#define CONFIG_PIC 0

	#define av_restrict
	#define __asm__ __asm
#endif

// Use DPRINTF instead of av_log. To be used for debug purpose because DPRINTF will be always called (the
// registry switch is not read)
#define USE_DPRINTF 0

#define FFMPEG_CONFIGURATION "ffmpeg configuration"
#define FFMPEG_LICENSE "GPL version 3 or later"

#define CC_TYPE "gcc"
#define CC_VERSION __VERSION__

#define ASMALIGN(ZEROBITS) ".p2align " #ZEROBITS "\n\t"

// MPC custom code for linking with MSVC
#if defined(__GNUC__) && ARCH_X86_64
	#define EXTERN_PREFIX ""
	#define EXTERN_ASM
#else
	#define EXTERN_PREFIX "_"
	#define EXTERN_ASM _
#endif

#define ARCH_AARCH64 0
#define ARCH_ALPHA 0
#define ARCH_ARM 0
#define ARCH_AVR32 0
#define ARCH_AVR32_AP 0
#define ARCH_AVR32_UC 0
#define ARCH_BFIN 0
#define ARCH_IA64 0
#define ARCH_LOONGARCH 0
#define ARCH_LOONGARCH32 0
#define ARCH_LOONGARCH64 0
#define ARCH_M68K 0
#define ARCH_MIPS 0
#define ARCH_MIPS64 0
#define ARCH_PARISC 0
#define ARCH_PPC 0
#define ARCH_PPC64 0
#define ARCH_RISCV 0
#define ARCH_S390 0
#define ARCH_SH4 0
#define ARCH_SPARC 0
#define ARCH_SPARC64 0
#define ARCH_TILEGX 0
#define ARCH_TILEPRO 0
#define ARCH_TOMI 0
#define HAVE_ALTIVEC 0
#define HAVE_ARMV5TE 0
#define HAVE_ARMV6 0
#define HAVE_ARMV6T2 0
#define HAVE_ARMV8 0
#define HAVE_NEON 0
#define HAVE_PPC4XX 0
#define HAVE_VSX 0
#define HAVE_VFP 0
#define HAVE_VFPV3 0
#define HAVE_SETEND 0
#define HAVE_MIPSFPU 0
#define HAVE_MIPS32R2 0
#define HAVE_MIPS32R5 0
#define HAVE_MIPS64R2 0
#define HAVE_MIPS32R6 0
#define HAVE_MIPS64R6 0
#define HAVE_MIPSDSP 0
#define HAVE_MIPSDSPR2 0
#define HAVE_MSA 0
#define HAVE_MMI 0
#define HAVE_LSX 0
#define HAVE_LASX 0
#define HAVE_ALTIVEC_EXTERNAL 0
#define HAVE_ARMV5TE_EXTERNAL 0
#define HAVE_ARMV6_EXTERNAL 0
#define HAVE_ARMV6T2_EXTERNAL 0
#define HAVE_ARMV8_EXTERNAL 0
#define HAVE_NEON_EXTERNAL 0
#define HAVE_PPC4XX_EXTERNAL 0
#define HAVE_VSX_EXTERNAL 0
#define HAVE_VFPV3_EXTERNAL 0
#define HAVE_MIPSFPU_EXTERNAL 0
#define HAVE_MIPS32R2_EXTERNAL 0
#define HAVE_MIPS32R5_EXTERNAL 0
#define HAVE_MIPS64R2_EXTERNAL 0
#define HAVE_MIPS32R6_EXTERNAL 0
#define HAVE_MIPS64R6_EXTERNAL 0
#define HAVE_MIPSDSP_EXTERNAL 0
#define HAVE_MIPSDSPR2_EXTERNAL 0
#define HAVE_MSA_EXTERNAL 0
#define HAVE_MMI_EXTERNAL 0
#define HAVE_LSX_EXTERNAL 0
#define HAVE_LASX_EXTERNAL 0
#define HAVE_ALTIVEC_INLINE 0
#define HAVE_ARMV5TE_INLINE 0
#define HAVE_ARMV6_INLINE 0
#define HAVE_ARMV6T2_INLINE 0
#define HAVE_ARMV8_INLINE 0
#define HAVE_NEON_INLINE 0
#define HAVE_PPC4XX_INLINE 0
#define HAVE_VSX_INLINE 0
#define HAVE_VFPV3_INLINE 0
#define HAVE_MIPSFPU_INLINE 0
#define HAVE_MIPS32R2_INLINE 0
#define HAVE_MIPS32R5_INLINE 0
#define HAVE_MIPS64R2_INLINE 0
#define HAVE_MIPS32R6_INLINE 0
#define HAVE_MIPS64R6_INLINE 0
#define HAVE_MIPSDSP_INLINE 0
#define HAVE_MIPSDSPR2_INLINE 0
#define HAVE_MSA_INLINE 0
#define HAVE_MMI_INLINE 0
#define HAVE_LSX_INLINE 0
#define HAVE_LASX_INLINE 0
#define HAVE_BIGENDIAN 0
#define HAVE_FAST_UNALIGNED 1
#define CONFIG_FAST_UNALIGNED 1
#define CONFIG_FFT 1
#define CONFIG_FREI0R 0
#define CONFIG_FTRAPV 0
#define HAVE_PTHREADS 0
#define HAVE_W32THREADS 1
#define HAVE_OS2THREADS 0
#define HAVE_AS_DN_DIRECTIVE 0
#define HAVE_AS_FPU_DIRECTIVE 0
#define HAVE_AS_FUNC 0
#define HAVE_ATOMIC_CAS_PTR 0
#define HAVE_ACCESS 1
#define HAVE_ALIGNED_MALLOC 1
#define HAVE_ARC4RANDOM 0
#define HAVE_ALIGNED_STACK 1
#define HAVE_ALSA_ASOUNDLIB_H 0
#define HAVE_ALTIVEC_H 0
#define HAVE_ARPA_INET_H 0
#define HAVE_ASM_TYPES_H 0
#define HAVE_CDIO_PARANOIA_H 0
#define HAVE_CDIO_PARANOIA_PARANOIA_H 0
#define HAVE_INTRINSICS_NEON 0
#define HAVE_ATANF 1
#define HAVE_ATAN2F 1
#define HAVE_CBRT 1
#define HAVE_CBRTF 1
#define HAVE_CLOCK_GETTIME 0
#define HAVE_CLOSESOCKET 0
#define HAVE_COSF 1
#define HAVE_ERF 1
#define HAVE_COMMANDLINETOARGVW 1
#define HAVE_CRYPTGENRANDOM 1
#define HAVE_DCBZL 0
#define HAVE_DCBZL_EXTERNAL 0
#define HAVE_DCBZL_INLINE 0
#define HAVE_DEV_BKTR_IOCTL_BT848_H 0
#define HAVE_DEV_BKTR_IOCTL_METEOR_H 0
#define HAVE_DEV_IC_BT8XX_H 0
#define HAVE_DEV_VIDEO_BKTR_IOCTL_BT848_H 0
#define HAVE_DEV_VIDEO_METEOR_IOCTL_METEOR_H 0
#define HAVE_DLFCN_H 0
#define HAVE_DLOPEN 0
#define HAVE_DOS_PATHS 1
#define HAVE_DXVA_H 1
#define HAVE_MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS 0
#define HAVE_BLOCKS_EXTENSION 0
#define HAVE_EBP_AVAILABLE 1
#define HAVE_EBX_AVAILABLE 1
#define HAVE_FAST_CLZ 1
#define HAVE_FAST_FLOAT16 0
#define HAVE_FCNTL 0
#define HAVE_FLT_LIM 1
#define HAVE_FORK 0
#define HAVE_GETADDRINFO 0
#define HAVE_GETAUXVAL 0
#define HAVE_GETENV 1
#define HAVE_GETHRTIME 0
#define HAVE_GETOPT 1
#define HAVE_GETPROCESSAFFINITYMASK 1
#define HAVE_GETPROCESSMEMORYINFO 1
#define HAVE_GETPROCESSTIMES 1
#define HAVE_GETSYSTEMTIMEASFILETIME 1
#define HAVE_GETRUSAGE 0
#define HAVE_GETTIMEOFDAY 1
#define HAVE_GLOB 0
#define HAVE_GLXGETPROCADDRESS 0
#define HAVE_GNU_AS 1
#define HAVE_GNU_WINDRES 0
#define HAVE_IBM_ASM 0
#define HAVE_GMTIME_R 0
#define HAVE_INET_ATON 0
#define HAVE_INLINE_ASM_LABELS 1
#define HAVE_INLINE_ASM_NONLOCAL_LABELS 1
#define HAVE_INLINE_ASM_DIRECT_SYMBOL_REFS 1
#define HAVE_ISATTY 0
#define HAVE_ISFINITE 1
#define HAVE_ISINF 1
#define HAVE_ISNAN 1
#define HAVE_JACK_PORT_GET_LATENCY_RANGE 0
#define HAVE_KBHIT 1
#define HAVE_POWER8 0
#define HAVE_POWER8_EXTERNAL 0
#define HAVE_POWER8_INLINE 0
#define HAVE_LDBRX 0
#define HAVE_LDBRX_EXTERNAL 0
#define HAVE_LDBRX_INLINE 0
#define HAVE_LDEXPF 1
#define HAVE_LIBDC1394_1 0
#define HAVE_LIBDC1394_2 0
#define HAVE_LLRINTF 1
#define HAVE_LOCAL_ALIGNED 1
#define HAVE_SIMD_ALIGN_16 1
#define HAVE_SIMD_ALIGN_32 1
#define HAVE_SIMD_ALIGN_64 1
#define HAVE_LOCALTIME_R 0
#define HAVE_LOG2 1
#define HAVE_LOG2F 1
#define HAVE_LOG10F 1
#define HAVE_LOONGSON2 0
#define HAVE_LOONGSON2_EXTERNAL 0
#define HAVE_LOONGSON2_INLINE 0
#define HAVE_LOONGSON3 0
#define HAVE_LOONGSON3_EXTERNAL 0
#define HAVE_LOONGSON3_INLINE 0
#define HAVE_LZO1X_999_COMPRESS 0
#define HAVE_DISPATCH_DISPATCH_H 0
#define HAVE_MACH_ABSOLUTE_TIME 0
#define HAVE_MACH_MACH_TIME_H 0
#define HAVE_MACHINE_IOCTL_BT848_H 0
#define HAVE_MACHINE_IOCTL_METEOR_H 0
#define HAVE_MACHINE_RW_BARRIER 0
#define HAVE_MAKEINFO 1
#define HAVE_MALLOC_H 1
#define HAVE_MAPVIEWOFFILE 1
#define HAVE_MEMALIGN 0
#define HAVE_MEMORYBARRIER 1
#define HAVE_MMAP 0
#define HAVE_MPROTECT 0
#define HAVE_MSVCRT 0
#define HAVE_NANOSLEEP 0
#define HAVE_OPENGL_GL3_H 0
#define HAVE_NETINET_SCTP_H 0
#define HAVE_PEEKNAMEDPIPE 1
#define HAVE_OPENCL_D3D11 0
#define HAVE_OPENCL_DRM_ARM 0
#define HAVE_OPENCL_DXVA2 0
#define HAVE_OPENCL_VAAPI_BEIGNET 0
#define HAVE_OPENCL_VAAPI_INTEL_MEDIA 0
#define HAVE_POD2MAN 1
#define HAVE_POLL_H 0
#define HAVE_POSIX_MEMALIGN 0
#define HAVE_PRAGMA_DEPRECATED 1
#define HAVE_POWF 1
#define HAVE_PTHREAD_CANCEL 0
#define HAVE_RSYNC_CONTIMEOUT 0
#define HAVE_SARESTART 0
#define HAVE_SEM_TIMEDWAIT 0
#define HAVE_RINT 1
#define HAVE_ROUNDF 1
#define HAVE_SCHED_GETAFFINITY 0
#define HAVE_SDL 0
#define HAVE_SDL2 0
#define HAVE_SETCONSOLETEXTATTRIBUTE 1
#define HAVE_SETMODE 1
#define HAVE_SETRLIMIT 0
#define HAVE_SINF 1
#define HAVE_SLEEP 1
#define HAVE_SNDIO_H 0
#define HAVE_SOCKLEN_T 0
#define HAVE_SOUNDCARD_H 0
#define HAVE_STRERROR_R 0
#define HAVE_STRUCT_ADDRINFO 0
#define HAVE_STRUCT_GROUP_SOURCE_REQ 0
#define HAVE_STRUCT_IP_MREQ_SOURCE 0
#define HAVE_STRUCT_IPV6_MREQ 0
#define HAVE_STRUCT_MSGHDR_MSG_FLAGS 0
#define HAVE_STRUCT_POLLFD 0
#define HAVE_STRUCT_RUSAGE_RU_MAXRSS 0
#define HAVE_STRUCT_SOCKADDR_IN6 0
#define HAVE_STRUCT_SOCKADDR_SA_LEN 0
#define HAVE_STRUCT_SOCKADDR_STORAGE 0
#define HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC 0
#define HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE 0
#define HAVE_SYMVER 1
#define HAVE_SYMVER_ASM_LABEL 1
#define HAVE_SYMVER_GNU_ASM 0
#define HAVE_SYNC_VAL_COMPARE_AND_SWAP 1
#define HAVE_CABS 0
#define HAVE_CEXP 0
#define HAVE_SYSCONF 0
#define HAVE_SYSCTL 0
#define HAVE_SYS_MMAN_H 0
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_RESOURCE_H 0
#define HAVE_SYS_SELECT_H 0
#define HAVE_SYS_SOUNDCARD_H 0
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_UN_H 0
#define HAVE_SYS_VIDEOIO_H 0
#define HAVE_TERMIOS_H 0
#define HAVE_TEXI2HTML 0
#define HAVE_THREADS 1
#define HAVE_UWP 0
#define HAVE_VAAPI_X11 0
#define HAVE_TRUNC 1
#define HAVE_TRUNCF 1
#define HAVE_UNISTD_H 1
#define HAVE_VALGRIND_VALGRIND_H 0
#define HAVE_USLEEP 1
#define HAVE_VDPAU_X11 0
#define HAVE_VFP_ARGS 0
#define HAVE_VIRTUALALLOC 1
#define HAVE_WGLGETPROCADDRESS 0
#define HAVE_WINDOWS_H 1
#define HAVE_WINSOCK2_H 0
#define HAVE_XFORM_ASM 0
#define HAVE_XLIB 0
#define CONFIG_DOC 0
#define CONFIG_AUDIOTOOLBOX 0
#define CONFIG_MEDIACODEC 0
#define CONFIG_VIDEOTOOLBOX 0
#define CONFIG_VIDEOTOOLBOX_HWACCEL 0
#define CONFIG_LIBVPL 0
#define CONFIG_OPENCL 0
#define CONFIG_VULKAN 0
#define CONFIG_CUDA 1
#define CONFIG_CUDA_NVCC 0
#define CONFIG_CUDA_SDK 0
#define CONFIG_CUDA_LLVM 0
#define CONFIG_ICONV 0
#define CONFIG_JNI 0
#define HAVE_X86ASM 1

#define HAVE_EXP2 1
#define HAVE_EXP2F 1
#define HAVE_EXPF 1
#define HAVE_HYPOT 1
#define HAVE_LLRINT 1
#define HAVE_LRINT 1
#define HAVE_LRINTF 1
#define HAVE_RDTSC 1
#define HAVE_ROUND 1

#ifdef __GNUC__
	#define HAVE_ATTRIBUTE_MAY_ALIAS 1
	#define HAVE_ATTRIBUTE_PACKED 1
#else
	#define HAVE_ATTRIBUTE_MAY_ALIAS 0
	#define HAVE_ATTRIBUTE_PACKED 0
#endif

#define CONFIG_DCT 1
#define CONFIG_DWT 0
#define CONFIG_GPL 1
#define CONFIG_VERSION3 1
#define CONFIG_AC3DSP 1
#define CONFIG_AUDIODSP 1
#define CONFIG_BLOCKDSP 1
#define CONFIG_BSWAPDSP 1
#define CONFIG_CABAC 1
#define CONFIG_DVPROFILE 1
#define CONFIG_FDCTDSP 1
#define CONFIG_ERROR_RESILIENCE 1
#define CONFIG_FRAME_THREAD_ENCODER 0
#define CONFIG_GPLV3 1
#define CONFIG_GRAY 1
#define CONFIG_H263DSP 1
#define CONFIG_H264CHROMA 1
#define CONFIG_H264DSP 1
#define CONFIG_H264PRED 1
#define CONFIG_H264QPEL 1
#define CONFIG_HPELDSP 1
#define CONFIG_HARDCODED_TABLES 0
#define CONFIG_HUFFMAN 1
#define CONFIG_HUFFYUVDSP 1
#define CONFIG_HUFFYUVENCDSP 0
#define CONFIG_IDCTDSP 1
#define CONFIG_MDCT15 1
#define CONFIG_INFLATE_WRAPPER 1
#define CONFIG_DEFLATE_WRAPPER 1
#define CONFIG_INTRAX8 1
#define CONFIG_LLAUDDSP 1
#define CONFIG_LLVIDDSP 1
#define CONFIG_LIBXVID 0
#define CONFIG_LIBZIMG 0
#define CONFIG_LIBTLS 0
#define CONFIG_LPC 0
#define CONFIG_MDCT 1
#define CONFIG_MEMORY_POISONING 0
#define CONFIG_NEON_CLOBBER_TEST 0
#define CONFIG_ME_CMP 1
#define CONFIG_MPEG_ER 1
#define CONFIG_MPEGAUDIODSP 1
#define CONFIG_MPEGVIDEO 1
#define CONFIG_MPEGVIDEODEC 1
#define CONFIG_MPEGVIDEOENC 0
#define CONFIG_MSMPEG4DEC 1
#define CONFIG_MSMPEG4ENC 0
#define CONFIG_PIXBLOCKDSP 1
#define CONFIG_QPELDSP 1
#define CONFIG_TPELDSP 1
#define CONFIG_VC1DSP 1
#define CONFIG_VIDEODSP 1
#define CONFIG_RAISE_MAJOR 0
#define CONFIG_RDFT 1
#define CONFIG_RUNTIME_CPUDETECT 1
#define CONFIG_SMALL 0
#define CONFIG_OPENAL 0
#define CONFIG_OPENCL 0
#define CONFIG_VULKAN 0
#define CONFIG_OPENGL 0
#define CONFIG_XLIB 0
#define CONFIG_ZLIB 1

#define CONFIG_DECODERS 1
#define CONFIG_ENCODERS 0
#define CONFIG_SWSCALE 1
#define CONFIG_SWSCALE_ALPHA 1
#define CONFIG_POSTPROC 0

/*
Note: when adding a new codec, you have to:
1)	Add a
	#define CONFIG_<codec suffix>_<ENCODER|DECODER|PARSER>
	depending on the type of codec you are adding
2)	Add a
	REGISTER_<ENCODER|DECODER|PARSER> (<codec suffix>, <codec suffix lowercase>);
	line to libavcodec/allcodecs.c
*/
#define CONFIG_MACOS_KPERF 0
#define CONFIG_BSFS 1

#define CONFIG_VDPAU 0

#define CONFIG_DXVA2 1
#define CONFIG_NVDEC 1
#define CONFIG_D3D11VA 1

#define CONFIG_DIRAC_PARSE 1

#define CONFIG_LIBSOXR 1

#define CONFIG_CBS 1
#define CONFIG_CBS_AV1 1

#endif /* FFMPEG_CONFIG_H */
