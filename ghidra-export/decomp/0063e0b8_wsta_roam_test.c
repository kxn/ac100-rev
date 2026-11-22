// func wsta_roam_test @ 0063e0b8 size=292

undefined4 wsta_roam_test(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_ac [16];
  int local_8c;
  undefined1 local_88;
  undefined1 local_87;
  uint local_44;
  undefined2 local_40;
  
  uVar1 = time((time_t *)0x0);
  srand(uVar1);
  for (iVar3 = 0; iVar3 < param_1; iVar3 = iVar3 + 1) {
    uVar1 = 1;
    memset(local_ac,0,0x80);
    local_88 = 1;
    local_8c = iVar3;
    while( true ) {
      uVar2 = rdmngr_profile_get_max_wlan_per_rd();
      if (uVar2 < uVar1) break;
      if (0 < param_2) {
        uVar2 = param_2 - 1;
        while( true ) {
          local_87 = (undefined1)uVar1;
          local_44 = uVar2 | uVar1 << 8 | 0x10000;
          local_40 = local_ac[0];
          wsta_db_sta_assoc(local_ac,uVar2,0,0,1,0,0);
          if ((int)uVar2 < 1) break;
          uVar2 = uVar2 - 1;
        }
      }
      uVar1 = uVar1 + 1;
    }
  }
  return 0;
}

