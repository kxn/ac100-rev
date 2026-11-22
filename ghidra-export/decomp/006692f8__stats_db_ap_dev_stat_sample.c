// func _stats_db_ap_dev_stat_sample @ 006692f8 size=868

undefined4 _stats_db_ap_dev_stat_sample(int param_1,undefined4 *param_2)

{
  byte *pbVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar6 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    uVar6 = 0;
    uVar8 = param_2[1];
    uVar7 = *param_2;
    if (*(int *)(param_1 + 0xc) != 0) {
      uVar4 = (uint)*(ushort *)(param_1 + 0x10);
      iVar2 = apmngr_db_get_ap_max();
      if ((int)uVar4 < iVar2) {
        iVar2 = apmngr_db_get_ap_max();
        if ((int)uVar4 < iVar2) {
          FUN_004082d0(l_stats_data,0xffffffff);
          pbVar5 = (byte *)(DAT_007cc8ec + uVar4 * 0x1e0);
          if (((pbVar5 != (byte *)0x0) && (*pbVar5 != 0)) && ((*pbVar5 & 8) == 0)) {
            if (9 < *(uint *)(pbVar5 + 0x60)) {
              memcpy(pbVar5 + 0x8c,pbVar5 + 0x90,0x24);
              memcpy(pbVar5 + 0xb4,pbVar5 + 0xb8,0x24);
              memcpy(pbVar5 + 0xdc,pbVar5 + 0xe0,0x24);
              memcpy(pbVar5 + 0x104,pbVar5 + 0x108,0x24);
              memcpy(pbVar5 + 300,pbVar5 + 0x130,0x24);
              memcpy(pbVar5 + 0x154,pbVar5 + 0x158,0x24);
              memcpy(pbVar5 + 0x17c,pbVar5 + 0x184,0x48);
              memcpy(pbVar5 + 0x1cc,pbVar5 + 0x1cd,9);
              pbVar5[0x60] = 0;
              pbVar5[0x61] = 0;
              pbVar5[0x62] = 0;
              pbVar5[99] = 9;
            }
            iVar2 = *(int *)(pbVar5 + 0x60);
            *(undefined4 *)(pbVar5 + (iVar2 + 0x54) * 4 + 4) = *(undefined4 *)(pbVar5 + 0x88);
            pbVar5[0x88] = 0;
            pbVar5[0x89] = 0;
            pbVar5[0x8a] = 0;
            pbVar5[0x8b] = 0;
            if ((*pbVar5 & 4) == 0) {
              pbVar5[0x78] = 0xff;
              pbVar5[0x79] = 0xff;
              pbVar5[0x7a] = 0xff;
              pbVar5[0x7b] = 0xff;
              pbVar5[0x74] = 0xff;
              pbVar5[0x75] = 0xff;
              pbVar5[0x76] = 0xff;
              pbVar5[0x77] = 0xff;
              pbVar5[0x7c] = 0xff;
              pbVar5[0x7d] = 0xff;
              pbVar5[0x7e] = 0xff;
              pbVar5[0x7f] = 0xff;
              pbVar5[0x80] = 0xff;
              pbVar5[0x81] = 0xff;
              pbVar5[0x82] = 0xff;
              pbVar5[0x83] = 0xff;
              pbVar5[0x84] = 0xff;
              pbVar5[0x85] = 0xff;
              pbVar5[0x86] = 0xff;
              pbVar5[0x87] = 0xff;
              pbVar1 = pbVar5 + (iVar2 + 0x2c) * 4 + 4;
              pbVar1[0] = 0xff;
              pbVar1[1] = 0xff;
              pbVar1[2] = 0xff;
              pbVar1[3] = 0xff;
              pbVar1 = pbVar5 + (iVar2 + 0x22) * 4 + 4;
              pbVar1[0] = 0xff;
              pbVar1[1] = 0xff;
              pbVar1[2] = 0xff;
              pbVar1[3] = 0xff;
              pbVar1 = pbVar5 + (iVar2 + 0x36) * 4 + 4;
              pbVar1[0] = 0xff;
              pbVar1[1] = 0xff;
              pbVar1[2] = 0xff;
              pbVar1[3] = 0xff;
              pbVar1 = pbVar5 + (iVar2 + 0x40) * 4 + 4;
              pbVar1[0] = 0xff;
              pbVar1[1] = 0xff;
              pbVar1[2] = 0xff;
              pbVar1[3] = 0xff;
              pbVar1 = pbVar5 + (iVar2 + 0x4a) * 4 + 4;
              pbVar1[0] = 0xff;
              pbVar1[1] = 0xff;
              pbVar1[2] = 0xff;
              pbVar1[3] = 0xff;
              pbVar5[(iVar2 + 0x2f) * 8 + 4] = 0xff;
              pbVar5[iVar2 * 8 + 0x17d] = 0xff;
              pbVar5[iVar2 * 8 + 0x17e] = 0xff;
              pbVar5[iVar2 * 8 + 0x17f] = 0xff;
              pbVar5[iVar2 * 8 + 0x180] = 0xff;
              pbVar5[iVar2 * 8 + 0x181] = 0xff;
              pbVar5[iVar2 * 8 + 0x182] = 0xff;
              pbVar5[iVar2 * 8 + 0x183] = 0xff;
              pbVar5[iVar2 + 0x1cc] = 0xff;
            }
            else {
              *(undefined4 *)(pbVar5 + (iVar2 + 0x2c) * 4 + 4) = *(undefined4 *)(pbVar5 + 0x78);
              pbVar5[0x78] = 0xff;
              pbVar5[0x79] = 0xff;
              pbVar5[0x7a] = 0xff;
              pbVar5[0x7b] = 0xff;
              *(undefined4 *)(pbVar5 + (iVar2 + 0x22) * 4 + 4) = *(undefined4 *)(pbVar5 + 0x74);
              pbVar5[0x74] = 0xff;
              pbVar5[0x75] = 0xff;
              pbVar5[0x76] = 0xff;
              pbVar5[0x77] = 0xff;
              *(undefined4 *)(pbVar5 + (iVar2 + 0x36) * 4 + 4) = *(undefined4 *)(pbVar5 + 0x7c);
              pbVar5[0x7c] = 0xff;
              pbVar5[0x7d] = 0xff;
              pbVar5[0x7e] = 0xff;
              pbVar5[0x7f] = 0xff;
              *(undefined4 *)(pbVar5 + (iVar2 + 0x40) * 4 + 4) = *(undefined4 *)(pbVar5 + 0x80);
              pbVar5[0x80] = 0xff;
              pbVar5[0x81] = 0xff;
              pbVar5[0x82] = 0xff;
              pbVar5[0x83] = 0xff;
              *(undefined4 *)(pbVar5 + (iVar2 + 0x4a) * 4 + 4) = *(undefined4 *)(pbVar5 + 0x84);
              pbVar5[0x84] = 0xff;
              pbVar5[0x85] = 0xff;
              pbVar5[0x86] = 0xff;
              pbVar5[0x87] = 0xff;
              memcpy(pbVar5 + iVar2 * 8 + 0x17c,pbVar5 + 0x19,8);
              pbVar5[iVar2 + 0x1cc] = pbVar5[0x21];
              *pbVar5 = *pbVar5 & 0xfb;
            }
            *(undefined4 *)(pbVar5 + 0x6c) = uVar8;
            *(undefined4 *)(pbVar5 + 0x68) = uVar7;
            *(int *)(pbVar5 + 0x60) = *(int *)(pbVar5 + 0x60) + 1;
          }
          FUN_00407f30(l_stats_data);
          return 0;
        }
        if (stats_warning_switch == '\0') {
          return 0;
        }
        pcVar3 = "stats_db_ap_global_sample";
        uVar7 = 0x2ed;
      }
      else {
        uVar6 = 0xffffffff;
        if (stats_warning_switch == '\0') {
          return 0xffffffff;
        }
        pcVar3 = "_stats_db_ap_dev_stat_sample";
        uVar7 = 0x44c;
      }
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n",pcVar3,uVar7,uVar4);
    }
  }
  return uVar6;
}

