// func wsta_add_test @ 0063dfb4 size=1

undefined4 wsta_add_test(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 auStack_a4 [16];
  int iStack_84;
  undefined1 uStack_80;
  undefined1 uStack_7f;
  uint uStack_3c;
  undefined2 uStack_38;
  
  uVar1 = time((time_t *)0x0);
  srand(uVar1);
  for (iVar5 = 0; iVar5 < param_1; iVar5 = iVar5 + 1) {
    memset(auStack_a4,0,0x80);
    iStack_84 = iVar5;
    for (uVar1 = 1; uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar1 <= uVar2; uVar1 = uVar1 + 1) {
      uStack_80 = (undefined1)uVar1;
      uVar2 = 1;
      while( true ) {
        uVar3 = rdmngr_profile_get_max_wlan_per_rd();
        uVar4 = uVar2 | uVar1 << 8 | iVar5 << 0x10;
        if (uVar3 < uVar2) break;
        uStack_7f = (undefined1)uVar2;
        uVar2 = uVar2 + 1;
        uStack_38 = auStack_a4[0];
        uStack_3c = uVar4;
        wsta_db_sta_assoc(auStack_a4,uVar1,0,0,0,0,0);
      }
    }
  }
  return 0;
}

