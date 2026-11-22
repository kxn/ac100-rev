// func capwap_dtls_data_destroy @ 005979d4 size=72

void capwap_dtls_data_destroy(undefined4 *param_1)

{
  gnutls_bye(*param_1,1);
  (*gnutls_free__GNUTLS_1_4)(param_1[0x15]);
  gnutls_deinit(*param_1);
  FUN_00407df0(param_1);
  return;
}

