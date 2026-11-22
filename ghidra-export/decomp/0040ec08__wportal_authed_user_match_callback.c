// func _wportal_authed_user_match_callback @ 0040ec08 size=568

bool _wportal_authed_user_match_callback(int param_1,undefined4 *param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  byte bVar4;
  char local_238 [324];
  char acStack_f4 [224];
  
  local_238[0] = '\0';
  local_238[1] = '\0';
  local_238[2] = '\0';
  local_238[3] = '\0';
  local_238[4] = '\0';
  local_238[5] = '\0';
  local_238[6] = '\0';
  local_238[7] = '\0';
  local_238[8] = '\0';
  local_238[9] = '\0';
  local_238[10] = '\0';
  local_238[0xb] = '\0';
  local_238[0xc] = '\0';
  local_238[0xd] = '\0';
  local_238[0xe] = '\0';
  local_238[0xf] = '\0';
  local_238[0x10] = '\0';
  local_238[0x11] = '\0';
  local_238[0x12] = '\0';
  local_238[0x13] = '\0';
  if (param_1 == 0) {
    return false;
  }
  if (param_2 == (undefined4 *)0x0) {
    return false;
  }
  switch(*param_2) {
  case 0:
    pcVar3 = (char *)(param_2 + 2);
    bVar1 = *(byte *)(param_1 + 0x80);
    iVar2 = strcmp(pcVar3,"web");
    bVar4 = bVar1 ^ 1;
    if (iVar2 != 0) {
      iVar2 = strcmp(pcVar3,"wechat");
      bVar4 = bVar1 ^ 2;
      if (iVar2 != 0) {
        iVar2 = strcmp(pcVar3,"onekey");
        bVar4 = bVar1 ^ 4;
        if (iVar2 != 0) {
          iVar2 = strcmp(pcVar3,"sms");
          bVar4 = bVar1 ^ 8;
          if (iVar2 != 0) {
            iVar2 = strcmp(pcVar3,"remote");
            bVar4 = bVar1 ^ 0x10;
            if (iVar2 != 0) {
              iVar2 = strcmp(pcVar3,"cmcc");
              bVar4 = bVar1 ^ 0x20;
              if (iVar2 != 0) {
                iVar2 = strcmp(pcVar3,"cloud");
                if (iVar2 != 0) {
                  return false;
                }
                bVar4 = bVar1 ^ 0x40;
              }
            }
          }
        }
      }
    }
    return bVar4 == 0;
  case 1:
    pcVar3 = (char *)(param_1 + 0xa3);
    FUN_00408150(pcVar3);
    break;
  default:
    return false;
  case 3:
    snprintf(local_238,0x14,"%02x-%02x-%02x-%02x-%02x-%02x",(uint)*(byte *)(param_1 + 0xc),
             (uint)*(byte *)(param_1 + 0xd),(uint)*(byte *)(param_1 + 0xe),
             (uint)*(byte *)(param_1 + 0xf),(uint)*(byte *)(param_1 + 0x10),
             (uint)*(byte *)(param_1 + 0x11));
    pcVar3 = local_238;
    break;
  case 4:
    if (g_portal_auth_mode != 1) {
      return false;
    }
    return *(int *)(param_1 + 0x14) == param_2[2];
  case 5:
    if (g_portal_auth_mode != 0) {
      return false;
    }
    memset(local_238 + 0x14,0,0x205);
    iVar2 = uac_wservice_get_entry_by_id(*(undefined4 *)(param_1 + 0x14),local_238 + 0x14);
    pcVar3 = acStack_f4;
    if (iVar2 != 0) {
      return false;
    }
  }
  pcVar3 = strstr(pcVar3,(char *)(param_2 + 2));
  return pcVar3 != (char *)0x0;
}

