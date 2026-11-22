// func tdcp_handle_from_ap @ 00511988 size=440

undefined4 tdcp_handle_from_ap(byte *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  void *__s;
  size_t __n;
  undefined4 uVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)(param_1 + 0xc);
  if ((param_2 == 0) || (param_3 == 0)) {
    if (tdcp_err_switch != 0) {
      pcVar4 = "[TDCP_ERROR]%s()/%d input para err.\n";
      uVar3 = 0x20d;
      goto LAB_00511a14;
    }
  }
  else if (param_1[2] == 0) {
    iVar2 = apmngr_db_get_id_by_mac(param_3);
    if (iVar2 == 0xffff) {
      if (tdcp_err_switch != 0) {
        pcVar4 = "[TDCP_ERROR]%s()/%d invaild ap id\n";
        uVar3 = 0x21a;
LAB_00511a14:
        printf(pcVar4,"tdcp_handle_from_ap",uVar3);
        return 0xffffffff;
      }
    }
    else {
      __s = (void *)FUN_00408450(0x1044,0x220);
      if (__s != (void *)0x0) {
        memset(__s,0,0x1044);
        *(uint *)((int)__s + 0xc) = (uint)*param_1;
        *(uint *)((int)__s + 0x14) = (uint)param_1[1];
        bVar1 = param_1[3];
        *(short *)((int)__s + 0x1038) = (short)iVar2;
        *(uint *)((int)__s + 0x10) = (uint)bVar1;
        __n = strlen(pcVar4);
        memcpy((void *)((int)__s + 0x38),pcVar4,__n);
        FUN_004082d0(tdcp_from_ap_mutex,0xffffffff);
        FUN_004086b0(&g_tdcp_from_ap_list,__s);
        FUN_004084b0(tdcp_from_ap_cond);
        FUN_00407f30(tdcp_from_ap_mutex);
        return 0;
      }
      if (tdcp_err_switch != 0) {
        pcVar4 = "[TDCP_ERROR]%s()/%d malloc error\n";
        uVar3 = 0x222;
        goto LAB_00511a14;
      }
    }
  }
  else if (tdcp_err_switch != 0) {
    printf("[TDCP_ERROR]%s()/%d unrecognized type:%d \n","tdcp_handle_from_ap",0x213);
    return 0xffffffff;
  }
  return 0xffffffff;
}

