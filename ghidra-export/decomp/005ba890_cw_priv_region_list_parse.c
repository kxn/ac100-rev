// func cw_priv_region_list_parse @ 005ba890 size=424

undefined4 cw_priv_region_list_parse(int param_1,int param_2)

{
  ushort uVar1;
  char *__s;
  char cVar4;
  undefined4 uVar2;
  int iVar3;
  uint uVar5;
  
  uVar1 = *(ushort *)(param_1 + 6);
  __s = (char *)FUN_00408450(8,0xaf);
  if (__s == (char *)0x0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[CW_ERROR]%32s():%4d out of memory\n","cw_priv_region_list_parse",0xb2);
    }
  }
  else {
    memset(__s,0,8);
    cVar4 = cw_protocol_retrieve8(param_1);
    *__s = cVar4;
    uVar5 = *(ushort *)(param_2 + 0xe) - 1;
    if (capwap_debug_switch == 0) {
      cVar4 = *__s;
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        cVar4 = *__s;
      }
      else {
        printf("[CW_DEBUG]%32s():%4d after retrieve pkt_buf\'s len=%d, max_len=%d, offset=%d, list_len=%d,msg_ele->len=%d\n"
               ,"cw_priv_region_list_parse",0xbb,(uint)*(ushort *)(param_1 + 4),
               *(undefined4 *)(param_1 + 8),(uint)*(ushort *)(param_1 + 6),uVar5,
               (uint)*(ushort *)(param_2 + 0xe));
        cVar4 = *__s;
      }
    }
    if (cVar4 != '\0') {
      iVar3 = cw_protocol_retrieve_raw_bytes(param_1,uVar5 & 0xffff);
      *(int *)(__s + 4) = iVar3;
      if (iVar3 == 0) {
        if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to parse \n","cw_priv_region_list_parse",0xc2);
        }
        FUN_00407df0(__s);
        return 0xffffffff;
      }
    }
    *(char **)(param_2 + 0x10) = __s;
    uVar2 = 0xffffffff;
    if ((uint)*(ushort *)(param_1 + 6) - (uint)uVar1 == (uint)*(ushort *)(param_2 + 0xe)) {
      uVar2 = 0;
    }
  }
  return uVar2;
}

