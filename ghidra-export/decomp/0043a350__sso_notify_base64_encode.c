// func _sso_notify_base64_encode @ 0043a350 size=320

/* WARNING: Removing unreachable block (ram,0x0043a38c) */
/* WARNING: Removing unreachable block (ram,0x0043a450) */

void _sso_notify_base64_encode(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  int local_10 [4];
  
  local_10[1] = 2;
  local_10[0] = 0;
  local_10[2] = 1;
  if (param_2 != (char *)0x0) {
    for (iVar2 = 0; *(char *)(param_1 + iVar2) != '\0'; iVar2 = iVar2 + 1) {
    }
    pcVar5 = param_2;
    iVar3 = 0;
    while (iVar3 < iVar2) {
      iVar4 = iVar3 + 1;
      uVar8 = 0;
      if (iVar4 < iVar2) {
        uVar8 = (uint)*(byte *)(param_1 + iVar4);
        iVar4 = iVar3 + 2;
      }
      uVar7 = 0;
      if (iVar4 < iVar2) {
        pbVar6 = (byte *)(param_1 + iVar4);
        iVar4 = iVar4 + 1;
        uVar7 = (uint)*pbVar6;
      }
      uVar7 = uVar8 * 0x100 + (uint)*(byte *)(param_1 + iVar3) * 0x10000 + uVar7;
      *pcVar5 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/_sso_notify_sangfor_server"
                [uVar7 * 0x100 >> 0x1a];
      pcVar5[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/_sso_notify_sangfor_server"
                  [uVar7 * 0x4000 >> 0x1a];
      cVar1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/_sso_notify_sangfor_server"
              [uVar7 & 0x3f];
      pcVar5[2] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/_sso_notify_sangfor_server"
                  [uVar7 * 0x100000 >> 0x1a];
      pcVar5[3] = cVar1;
      pcVar5 = pcVar5 + 4;
      iVar3 = iVar4;
    }
    param_2 = param_2 + ((iVar2 + 2) / 3) * 4;
    iVar3 = local_10[iVar2 % 3];
    for (iVar2 = 0; param_2 = param_2 + -1, iVar2 < iVar3; iVar2 = iVar2 + 1) {
      *param_2 = '=';
    }
  }
  return;
}

