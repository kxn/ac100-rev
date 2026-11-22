// func apupd_db_wtp_firmware_id_match @ 006549e8 size=216

bool apupd_db_wtp_firmware_id_match(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return false;
  }
  if (param_2 == 0) {
    return false;
  }
  if (apupd_need_firmware_check == 0) {
    return true;
  }
  iVar3 = 0;
  do {
    if (*(int *)(param_2 + 0x614) <= iVar3) {
      iVar3 = 0;
      do {
        bVar1 = iVar3 < (int)(uint)*(byte *)(param_1 + 0x68);
        if (!bVar1) {
          return bVar1;
        }
        iVar2 = memcmp((void *)(param_2 + 4),(void *)(param_1 + iVar3 * 0x10 + 0x69),0x10);
        iVar3 = iVar3 + 1;
      } while (iVar2 != 0);
      return true;
    }
    iVar3 = iVar3 + 1;
    iVar2 = memcmp((void *)(param_1 + 0x58),(void *)(param_2 + iVar3 * 0x10 + 4),0x10);
  } while (iVar2 != 0);
  return true;
}

