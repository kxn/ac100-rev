// func capwap_dtls_data_init @ 00597914 size=192

undefined4 capwap_dtls_data_init(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  gnutls_init(param_1,0xd);
  gnutls_credentials_set(*param_1,1,*param_2);
  gnutls_dtls_set_mtu(*param_1,0x578);
  gnutls_set_default_priority(*param_1);
  gnutls_transport_set_ptr(*param_1,param_3);
  gnutls_transport_set_push_function(*param_1,push_func);
  gnutls_transport_set_pull_function(*param_1,pull_func);
  gnutls_transport_set_pull_timeout_function(*param_1,pull_timeout_func);
  param_1[0x18] = 0;
  param_1[0x19] = capwap_dtls_fsm_process;
  gnutls_key_generate(param_1 + 0x15,0x10);
  return 0;
}

