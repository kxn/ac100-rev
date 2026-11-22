// func _nbr_filter @ 004861a4 size=296

bool _nbr_filter(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  
  iVar2 = get_wireless_cur_network_mode();
  if (iVar2 == 2) {
    if (param_4 == 0) {
      cVar3 = -0x4b;
      if ((*(byte *)(param_3 + 0xe) & 1) != 0) {
        cVar3 = *(char *)(param_3 + 0xf);
      }
    }
    else {
      cVar3 = -0x50;
      if ((*(byte *)(param_3 + 0x15) & 1) != 0) {
        cVar3 = *(char *)(param_3 + 0x16);
      }
    }
    if (*(char *)(param_5 + 0xc) <= cVar3) {
      return true;
    }
    bVar1 = wsta_roam_chl_load_max_2g;
    if (param_4 == 1) {
      bVar1 = wsta_roam_chl_load_max_5g;
    }
    if (bVar1 < *(byte *)(param_5 + 9)) {
      return true;
    }
  }
  if (param_2 == 0) {
    if (param_4 == 1) {
      iVar2 = (int)*(char *)(param_5 + 0xc);
      goto LAB_00486204;
    }
    cVar3 = *(char *)(param_5 + 0xc);
  }
  else if (param_2 == 1) {
    cVar3 = *(char *)(param_5 + 0xc);
    if (param_4 == 0) {
      iVar2 = (int)(char)((cVar3 - wsta_roam_5gto2g_fix) - *(char *)(param_3 + 0x1d));
      goto LAB_00486204;
    }
  }
  else {
    cVar3 = *(char *)(param_5 + 0xc);
  }
  iVar2 = (int)(char)(cVar3 - *(char *)(param_3 + 0x1d));
LAB_00486204:
  return iVar2 < param_1;
}

