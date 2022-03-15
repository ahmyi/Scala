package=libiconv
$(package)_version=1.16
$(package)_download_path=https://ftp.gnu.org/gnu/libiconv
$(package)_file_name=libiconv-$($(package)_version).tar.gz
$(package)_sha256_hash=e6a1b1b589654277ee790cce3734f07876ac4ccfaecbee8afa0b649cf529cc04
# $(package)_patches=fix-whitespace.patch

define $(package)_set_vars
  $(package)_config_opts=--disable-nls
  $(package)_config_opts=--enable-static
  $(package)_config_opts=--disable-shared
  $(package)_config_opts_linux=--with-pic
  $(package)_config_opts_freebsd=--with-pic
endef

define $(package)_preprocess_cmds
  cp -f $(BASEDIR)/config.guess $(BASEDIR)/config.sub build-aux/
  # &&\ patch -p1 < $($(package)_patch_dir)/fix-whitespace.patch
endef

define $(package)_config_cmds
  $($(package)_autoconf) AR_FLAGS=$($(package)_arflags)
endef

define $(package)_build_cmds
  $(MAKE)
endef

define $(package)_stage_cmds
  $(MAKE) DESTDIR=$($(package)_staging_dir) install
endef

define $(package)_postprocess_cmds
  rm lib/*.la
endef
