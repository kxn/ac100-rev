// func uac_com_get_dev_vendor_name @ 0051712c size=160

undefined4 uac_com_get_dev_vendor_name(char *param_1,size_t param_2)

{
  int iVar1;
  char *__format;
  
  iVar1 = uac_com_get_dev_vendor();
  if (iVar1 == 1) {
    __format = "MERCURY";
  }
  else if (iVar1 == 2) {
    __format = "FAST";
  }
  else {
    __format = "TP-LINK";
  }
  snprintf(param_1,param_2,__format);
  return 0;
}

