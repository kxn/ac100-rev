// func uac_ipaddr_transfer_binary2uacip @ 0051aa9c size=232

undefined4 uac_ipaddr_transfer_binary2uacip(undefined4 *param_1,int param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == (undefined4 *)0x0) || (1 < param_2 - 1U)) {
    uVar1 = 0xffffffff;
    if (uac_ip_err_switch != 0) {
      printf("[UAC_IP_ERROR]%s()/line %d : Invalid params.\n","uac_ipaddr_transfer_binary2uacip",
             0x8f);
    }
  }
  else {
    memset(param_3,0,0x14);
    if (param_2 == 1) {
      *param_3 = 1;
      *(undefined4 *)(param_3 + 4) = *param_1;
      uVar1 = 0;
    }
    else {
      *param_3 = 2;
      memcpy(param_3 + 4,param_1,0x10);
      uVar1 = 0;
    }
  }
  return uVar1;
}

