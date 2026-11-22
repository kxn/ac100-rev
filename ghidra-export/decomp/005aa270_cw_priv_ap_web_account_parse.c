// func cw_priv_ap_web_account_parse @ 005aa270 size=672

undefined4 cw_priv_ap_web_account_parse(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *__s;
  undefined2 uVar4;
  int iVar2;
  void *pvVar3;
  char *__format;
  undefined4 uVar5;
  uint uVar6;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (undefined2 *)FUN_00408450(0xc,0x5f);
  if (__s == (undefined2 *)0x0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_ap_web_account_parse",0x62);
    return 0xffffffff;
  }
  memset(__s,0,0xc);
  uVar4 = cw_protocol_retrieve16(param_1);
  *__s = uVar4;
  iVar2 = cw_protocol_retrieve8(param_1);
  *(char *)(__s + 1) = (char)iVar2;
  if (iVar2 - 1U < 0x40) {
    iVar2 = cw_protocol_retrieve8(param_1);
    *(char *)((int)__s + 3) = (char)iVar2;
    if (iVar2 - 1U < 0x40) {
      pvVar3 = (void *)FUN_00408450(*(byte *)(__s + 1) + 1,0x75);
      *(void **)(__s + 2) = pvVar3;
      if (pvVar3 != (void *)0x0) {
        memset(pvVar3,0,*(byte *)(__s + 1) + 1);
        cw_protocol_retrieve_bytes(param_1,*(undefined4 *)(__s + 2),*(undefined1 *)(__s + 1));
        pvVar3 = (void *)FUN_00408450(*(byte *)((int)__s + 3) + 1,0x7e);
        *(void **)(__s + 4) = pvVar3;
        if (pvVar3 != (void *)0x0) {
          memset(pvVar3,0,*(byte *)((int)__s + 3) + 1);
          cw_protocol_retrieve_bytes(param_1,*(undefined4 *)(__s + 4),*(undefined1 *)((int)__s + 3))
          ;
          *(undefined2 **)(param_2 + 0x10) = __s;
          if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 != (uint)*(ushort *)(param_2 + 0xe)) {
            return 0xffffffff;
          }
          return 0;
        }
        if (capwap_err_switch == 0) {
          iVar2 = *(int *)(__s + 2);
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            iVar2 = *(int *)(__s + 2);
          }
          else {
            printf("[CW_ERROR]%32s():%4d malloc password failed len:%d\n",
                   "cw_priv_ap_web_account_parse",0x81,(uint)*(byte *)((int)__s + 3));
            iVar2 = *(int *)(__s + 2);
          }
        }
        if (iVar2 != 0) {
          FUN_00407df0();
        }
        goto LAB_005aa400;
      }
      if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005aa400;
      uVar6 = (uint)*(byte *)(__s + 1);
      __format = "[CW_ERROR]%32s():%4d malloc username failed len:%d\n";
      uVar5 = 0x78;
    }
    else {
      if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005aa400;
      uVar6 = (uint)*(byte *)((int)__s + 3);
      __format = "[CW_ERROR]%32s():%4d  password len:%d error\n";
      uVar5 = 0x71;
    }
  }
  else {
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005aa400;
    uVar6 = (uint)*(byte *)(__s + 1);
    __format = "[CW_ERROR]%32s():%4d  username len:%d error\n";
    uVar5 = 0x6a;
  }
  printf(__format,"cw_priv_ap_web_account_parse",uVar5,uVar6);
LAB_005aa400:
  FUN_00407df0(__s);
  return 0xffffffff;
}

