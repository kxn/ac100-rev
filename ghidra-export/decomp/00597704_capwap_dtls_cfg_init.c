// func capwap_dtls_cfg_init @ 00597704 size=352

undefined4 * capwap_dtls_cfg_init(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *__s;
  int iVar1;
  
  __s = (undefined4 *)FUN_00408450(0xcd04,0x150);
  if (__s == (undefined4 *)0x0) {
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory.\n","capwap_dtls_cfg_init",0x152);
    }
  }
  else {
    memset(__s,0,0xcd04);
    snprintf((char *)(__s + 1),0x80,"%s",param_2);
    snprintf((char *)(__s + 0x21),0x80,"%s",param_3);
    gnutls_certificate_allocate_credentials(__s);
    iVar1 = gnutls_certificate_set_x509_key_file(*__s,__s + 1,__s + 0x21,1);
    if (iVar1 < 0) {
      gnutls_certificate_free_credentials(*__s);
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d No certificate or key were found.\n","capwap_dtls_cfg_init",
               0x160);
      }
      FUN_00407df0(__s);
      __s = (undefined4 *)0x0;
    }
    else {
      gnutls_certificate_set_verify_function(*__s,0);
    }
  }
  return __s;
}

