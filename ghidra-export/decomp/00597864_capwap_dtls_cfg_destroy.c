// func capwap_dtls_cfg_destroy @ 00597864 size=1

void capwap_dtls_cfg_destroy(undefined4 *param_1)

{
  gnutls_certificate_free_credentials(*param_1);
  uac_mem_free_my(param_1);
  return;
}

