// func push_func @ 005975b4 size=320

int push_func(undefined4 *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  memcpy((void *)param_1[0x10],&DAT_006e3578,4);
  memcpy((void *)(param_1[0x10] + 4),param_2,param_3);
  if (*(char *)(param_1 + 8) == '\x01') {
    iVar1 = capwap_plain_packet_send(*param_1,param_1 + 8,param_1 + 1,param_1[0x10],param_3 + 4);
    if (-1 < iVar1) {
      return iVar1 + -4;
    }
    if (capwap_warning_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    uVar2 = 0x47;
  }
  else {
    if (*(char *)(param_1 + 8) != '\x02') {
      return -1;
    }
    iVar1 = capwap_plain_ipv6_packet_send
                      (*param_1,param_1 + 8,param_1 + 1,param_1[0x10],param_3 + 4);
    if (-1 < iVar1) {
      return iVar1 + -4;
    }
    if (capwap_warning_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    uVar2 = 0x54;
  }
  printf("[CW_WARNING]%32s():%4d BIO packet send failed\n","push_func",uVar2);
  return -1;
}

