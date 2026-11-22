// func _wportal_nsa_match_callback @ 0040ee40 size=360

bool _wportal_nsa_match_callback(int param_1,undefined4 *param_2)

{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  char local_230 [324];
  char acStack_ec [220];
  
  bVar3 = false;
  local_230[0] = '\0';
  local_230[1] = '\0';
  local_230[2] = '\0';
  local_230[3] = '\0';
  local_230[4] = '\0';
  local_230[5] = '\0';
  local_230[6] = '\0';
  local_230[7] = '\0';
  local_230[8] = '\0';
  local_230[9] = '\0';
  local_230[10] = '\0';
  local_230[0xb] = '\0';
  local_230[0xc] = '\0';
  local_230[0xd] = '\0';
  local_230[0xe] = '\0';
  local_230[0xf] = '\0';
  local_230[0x10] = '\0';
  local_230[0x11] = '\0';
  local_230[0x12] = '\0';
  local_230[0x13] = '\0';
  if (param_1 == 0) {
    return false;
  }
  if (param_2 == (undefined4 *)0x0) {
    return false;
  }
  switch(*param_2) {
  case 1:
    pcVar1 = (char *)(param_1 + 0x7a);
    goto LAB_0040ef54;
  case 2:
    if (*(char *)(param_1 + 0x166) != '\0') {
      return false;
    }
    pcVar1 = (char *)(param_1 + 0xc);
LAB_0040ef54:
    FUN_00408150(pcVar1);
    break;
  case 3:
    snprintf(local_230,0x14,"%02x-%02x-%02x-%02x-%02x-%02x",(uint)*(byte *)(param_1 + 0x74),
             (uint)*(byte *)(param_1 + 0x75),(uint)*(byte *)(param_1 + 0x76),
             (uint)*(byte *)(param_1 + 0x77),(uint)*(byte *)(param_1 + 0x78),
             (uint)*(byte *)(param_1 + 0x79));
    pcVar1 = local_230;
    break;
  case 4:
    if (g_portal_auth_mode != 1) {
      return false;
    }
    return *(int *)(param_1 + 0x128) == param_2[2];
  case 5:
    if (g_portal_auth_mode != 0) {
      return false;
    }
    memset(local_230 + 0x14,0,0x205);
    iVar2 = uac_wservice_get_entry_by_id(*(undefined4 *)(param_1 + 0x128),local_230 + 0x14);
    if (iVar2 != 0) {
      return false;
    }
    pcVar1 = acStack_ec;
    break;
  default:
    goto switchD_0040eec0_default;
  }
  pcVar1 = strstr(pcVar1,(char *)(param_2 + 2));
  bVar3 = pcVar1 != (char *)0x0;
switchD_0040eec0_default:
  return bVar3;
}

