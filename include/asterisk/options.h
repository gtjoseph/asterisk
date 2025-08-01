/*
 * Asterisk -- An open source telephony toolkit.
 *
 * Copyright (C) 1999 - 2005, Digium, Inc.
 *
 * Mark Spencer <markster@digium.com>
 *
 * See http://www.asterisk.org for more information about
 * the Asterisk project. Please do not directly contact
 * any of the maintainers of this project for assistance;
 * the project provides a web site, mailing lists and IRC
 * channels for your use.
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License Version 2. See the LICENSE file
 * at the top of the source tree.
 */

/*! \file
 * \brief Options provided by main asterisk program
 */

#ifndef _ASTERISK_OPTIONS_H
#define _ASTERISK_OPTIONS_H

#include "asterisk/autoconfig.h"

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#define AST_CACHE_DIR_LEN 	512
#define AST_FILENAME_MAX	80
#define AST_CHANNEL_NAME    80  /*!< Max length of an ast_channel name */
#define AST_CHANNEL_STORAGE_BACKEND_NAME_LEN  80  /*!< Max length of storage backend name */


/*! \ingroup main_options */
enum ast_option_flags {
	/*! Allow \#exec in config files */
	AST_OPT_FLAG_EXEC_INCLUDES = (1 << 0),
	/*! Do not fork() */
	AST_OPT_FLAG_NO_FORK = (1 << 1),
	/*! Keep quiet */
	AST_OPT_FLAG_QUIET = (1 << 2),
	/*! Console mode */
	AST_OPT_FLAG_CONSOLE = (1 << 3),
	/*! Run in realtime Linux priority */
	AST_OPT_FLAG_HIGH_PRIORITY = (1 << 4),
	/*! Initialize keys for RSA authentication */
	AST_OPT_FLAG_INIT_KEYS = (1 << 5),
	/*! Remote console */
	AST_OPT_FLAG_REMOTE = (1 << 6),
	/*! Execute an asterisk CLI command upon startup */
	AST_OPT_FLAG_EXEC = (1 << 7),
	/*! Don't use termcap colors */
	AST_OPT_FLAG_NO_COLOR = (1 << 8),
	/*! Are we fully started yet? */
	AST_OPT_FLAG_FULLY_BOOTED = (1 << 9),
	/*! Trascode via signed linear */
	AST_OPT_FLAG_TRANSCODE_VIA_SLIN = (1 << 10),
	/*! Invoke the stdexten using the legacy macro method. */
	AST_OPT_FLAG_STDEXTEN_MACRO = (1 << 11),
	/*! Dump core on a seg fault */
	AST_OPT_FLAG_DUMP_CORE = (1 << 12),
	/*! Cache sound files */
	AST_OPT_FLAG_CACHE_RECORD_FILES = (1 << 13),
	/*! Display timestamp in CLI verbose output */
	AST_OPT_FLAG_TIMESTAMP = (1 << 14),
	/*! Cache media frames for performance */
	AST_OPT_FLAG_CACHE_MEDIA_FRAMES = (1 << 15),
	/*! Reconnect */
	AST_OPT_FLAG_RECONNECT = (1 << 16),
	/*! Transmit Silence during Record() and DTMF Generation */
	AST_OPT_FLAG_TRANSMIT_SILENCE = (1 << 17),
	/*! Suppress some warnings */
	AST_OPT_FLAG_DONT_WARN = (1 << 18),
	/*! Search custom directory for sounds first */
	AST_OPT_FLAG_SOUNDS_SEARCH_CUSTOM = (1 << 19),
	/*! Reference Debugging */
	AST_OPT_FLAG_REF_DEBUG = (1 << 20),
	/*! Always fork, even if verbose or debug settings are non-zero */
	AST_OPT_FLAG_ALWAYS_FORK = (1 << 21),
	/*! Disable log/verbose output to remote consoles */
	AST_OPT_FLAG_MUTE = (1 << 22),
	/*! There is a per-module debug setting */
	AST_OPT_FLAG_DEBUG_MODULE = (1 << 23),
	/*! There is a per-module trace setting */
	AST_OPT_FLAG_TRACE_MODULE = (1 << 24),
	/*! Terminal colors should be adjusted for a light-colored background */
	AST_OPT_FLAG_LIGHT_BACKGROUND = (1 << 25),
	/*! Make the global Message channel an internal channel to suppress AMI events */
	AST_OPT_FLAG_HIDE_MESSAGING_AMI_EVENTS = (1 << 26),
	/*! Force black background */
	AST_OPT_FLAG_FORCE_BLACK_BACKGROUND = (1 << 27),
	/*! Hide remote console connect messages on console */
	AST_OPT_FLAG_HIDE_CONSOLE_CONNECT = (1 << 28),
	/*! Protect the configuration file path with a lock */
	AST_OPT_FLAG_LOCK_CONFIG_DIR = (1 << 29),
	/*! Generic PLC */
	AST_OPT_FLAG_GENERIC_PLC = (1 << 30),
	/*! Generic PLC onm equal codecs */
	AST_OPT_FLAG_GENERIC_PLC_ON_EQUAL_CODECS = (1 << 31),
	/*!
	 * ast_options is now an ast_flags64 structure so if you add more
	 * options, make sure to use (1ULL << <bits>) to ensure that the
	 * enum itself is allocated as a uint64_t instead of the default
	 * uint32_t.  Attmpting to simply shift a 1 by more than 31 bits
	 * will result in a "shift-count-overflow" compile failure.
	 * Example:
	 * AST_OPT_FLAG_NEW_OPTION = (1ULL << 32),
	 */
};

/*! These are the options that set by default when Asterisk starts */
#define AST_DEFAULT_OPTIONS (AST_OPT_FLAG_TRANSCODE_VIA_SLIN | AST_OPT_FLAG_CACHE_MEDIA_FRAMES)

#define ast_opt_exec_includes		ast_test_flag64(&ast_options, AST_OPT_FLAG_EXEC_INCLUDES)
#define ast_opt_no_fork			ast_test_flag64(&ast_options, AST_OPT_FLAG_NO_FORK)
#define ast_opt_quiet			ast_test_flag64(&ast_options, AST_OPT_FLAG_QUIET)
#define ast_opt_console			ast_test_flag64(&ast_options, AST_OPT_FLAG_CONSOLE)
#define ast_opt_high_priority		ast_test_flag64(&ast_options, AST_OPT_FLAG_HIGH_PRIORITY)
#define ast_opt_init_keys		ast_test_flag64(&ast_options, AST_OPT_FLAG_INIT_KEYS)
#define ast_opt_remote			ast_test_flag64(&ast_options, AST_OPT_FLAG_REMOTE)
#define ast_opt_exec			ast_test_flag64(&ast_options, AST_OPT_FLAG_EXEC)
#define ast_opt_no_color		ast_test_flag64(&ast_options, AST_OPT_FLAG_NO_COLOR)
#define ast_fully_booted		ast_test_flag64(&ast_options, AST_OPT_FLAG_FULLY_BOOTED)
#define ast_opt_transcode_via_slin	ast_test_flag64(&ast_options, AST_OPT_FLAG_TRANSCODE_VIA_SLIN)
#define ast_opt_dump_core		ast_test_flag64(&ast_options, AST_OPT_FLAG_DUMP_CORE)
#define ast_opt_cache_record_files	ast_test_flag64(&ast_options, AST_OPT_FLAG_CACHE_RECORD_FILES)
#define ast_opt_cache_media_frames	ast_test_flag64(&ast_options, AST_OPT_FLAG_CACHE_MEDIA_FRAMES)
#define ast_opt_timestamp		ast_test_flag64(&ast_options, AST_OPT_FLAG_TIMESTAMP)
#define ast_opt_reconnect		ast_test_flag64(&ast_options, AST_OPT_FLAG_RECONNECT)
#define ast_opt_transmit_silence	ast_test_flag64(&ast_options, AST_OPT_FLAG_TRANSMIT_SILENCE)
#define ast_opt_dont_warn		ast_test_flag64(&ast_options, AST_OPT_FLAG_DONT_WARN)
#define ast_opt_always_fork		ast_test_flag64(&ast_options, AST_OPT_FLAG_ALWAYS_FORK)
#define ast_opt_mute			ast_test_flag64(&ast_options, AST_OPT_FLAG_MUTE)
#define ast_opt_dbg_module		ast_test_flag64(&ast_options, AST_OPT_FLAG_DEBUG_MODULE)
#define ast_opt_trace_module		ast_test_flag64(&ast_options, AST_OPT_FLAG_TRACE_MODULE)
#define ast_opt_light_background	ast_test_flag64(&ast_options, AST_OPT_FLAG_LIGHT_BACKGROUND)
#define ast_opt_force_black_background	ast_test_flag64(&ast_options, AST_OPT_FLAG_FORCE_BLACK_BACKGROUND)
#define ast_opt_hide_connect		ast_test_flag64(&ast_options, AST_OPT_FLAG_HIDE_CONSOLE_CONNECT)
#define ast_opt_lock_confdir		ast_test_flag64(&ast_options, AST_OPT_FLAG_LOCK_CONFIG_DIR)
#define ast_opt_generic_plc         ast_test_flag64(&ast_options, AST_OPT_FLAG_GENERIC_PLC)
#define ast_opt_ref_debug           ast_test_flag64(&ast_options, AST_OPT_FLAG_REF_DEBUG)
#define ast_opt_generic_plc_on_equal_codecs  ast_test_flag64(&ast_options, AST_OPT_FLAG_GENERIC_PLC_ON_EQUAL_CODECS)
#define ast_opt_hide_messaging_ami_events  ast_test_flag64(&ast_options, AST_OPT_FLAG_HIDE_MESSAGING_AMI_EVENTS)
#define ast_opt_sounds_search_custom ast_test_flag64(&ast_options, AST_OPT_FLAG_SOUNDS_SEARCH_CUSTOM)

/*! Maximum log level defined by PJPROJECT. */
#define MAX_PJ_LOG_MAX_LEVEL		6
/*!
 * Normal PJPROJECT active log level used by Asterisk.
 *
 * These levels are usually mapped to Error and
 * Warning Asterisk log levels which shouldn't
 * normally be suppressed.
 */
#define DEFAULT_PJ_LOG_MAX_LEVEL	2

/*!
 * \brief Get maximum log level pjproject was compiled with.
 *
 * \details
 * Determine the maximum log level the pjproject we are running
 * with supports.
 *
 * When pjproject is initially loaded the default log level in
 * effect is the maximum log level the library was compiled to
 * generate.  We must save this value off somewhere before we
 * change it to what we want to use as the default level.
 *
 * \note This must be done before calling pj_init() so the level
 * we want to use as the default level is in effect while the
 * library initializes.
 */
#define AST_PJPROJECT_INIT_LOG_LEVEL()							\
	do {														\
		if (ast_pjproject_max_log_level < 0) {					\
			ast_pjproject_max_log_level = pj_log_get_level();	\
		}														\
		pj_log_set_level(ast_option_pjproject_log_level);		\
	} while (0)

/*! Current linked pjproject maximum logging level */
extern int ast_pjproject_max_log_level;

#define DEFAULT_PJPROJECT_CACHE_POOLS	1

/*! Current pjproject pool caching enable */
extern int ast_option_pjproject_cache_pools;

/*! Current pjproject logging level */
extern int ast_option_pjproject_log_level;

extern struct ast_flags64 ast_options;

extern int option_verbose;
extern int ast_option_maxfiles;		/*!< Max number of open file handles (files, sockets) */
extern int option_debug;		/*!< Debugging */
extern int option_trace;		/*!< Debugging */
extern int ast_option_maxcalls;		/*!< Maximum number of simultaneous channels */
extern unsigned int option_dtmfminduration;	/*!< Minimum duration of DTMF (channel.c) in ms */
extern double ast_option_maxload;
#if defined(HAVE_SYSINFO)
extern long option_minmemfree;		/*!< Minimum amount of free system memory - stop accepting calls if free memory falls below this watermark */
#endif
extern char ast_defaultlanguage[];

extern struct timeval ast_startuptime;
extern struct timeval ast_lastreloadtime;
extern pid_t ast_mainpid;

extern char record_cache_dir[AST_CACHE_DIR_LEN];

extern int ast_language_is_prefix;

extern int ast_option_rtpusedynamic;
extern unsigned int ast_option_rtpptdynamic;

extern int ast_option_disable_remote_console_shell;

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif /* _ASTERISK_OPTIONS_H */
