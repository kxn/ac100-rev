// func _stats_sta_sample_handle @ 006683cc size=848

void _stats_sta_sample_handle(int param_1,undefined4 *param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char *__format;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 auStack_2f0 [732];
  
  memset(auStack_2f0,0,0x2d8);
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    if (stats_err_switch == '\0') {
      return;
    }
    __format = "[STATISTICS_ERROR]%s()/%d invalid params\n";
    uVar8 = 0x209;
  }
  else {
    uVar9 = param_2[1];
    uVar8 = *param_2;
    uVar3 = *(ushort *)(param_1 + 8);
    iVar4 = apmngr_db_get_ap_max();
    if ((((iVar4 <= (int)(uint)uVar3) || (bVar1 = *(byte *)(param_1 + 10), bVar1 == 0)) ||
        (uVar5 = rdmngr_profile_get_max_rd_per_ap(), uVar5 < bVar1)) ||
       ((bVar1 = *(byte *)(param_1 + 0xb), bVar1 == 0 ||
        (uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar5 < bVar1)))) {
      if (stats_warning_switch == '\0') {
        return;
      }
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","_stats_sta_sample_handle",0x212,
             (uint)*(ushort *)(param_1 + 8),(uint)*(byte *)(param_1 + 10),
             (uint)*(byte *)(param_1 + 0xb));
      return;
    }
    iVar4 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 8),auStack_2f0);
    if (iVar4 != -1) {
      if ((*(byte *)(param_1 + 0xc) & 0x18) != 0x10) {
        return;
      }
      if (*(byte *)(param_1 + 0x55) < 10) {
        bVar1 = *(byte *)(param_1 + 0xc);
      }
      else {
        memcpy((void *)(param_1 + 0x68),(void *)(param_1 + 0x6c),0x24);
        memcpy((void *)(param_1 + 0x90),(void *)(param_1 + 0x94),0x24);
        memcpy((void *)(param_1 + 0xb8),(void *)(param_1 + 0xbc),0x24);
        memcpy((void *)(param_1 + 0xe0),(void *)(param_1 + 0xe4),0x24);
        memcpy((void *)(param_1 + 0x108),(void *)(param_1 + 0x109),9);
        memcpy((void *)(param_1 + 0x112),(void *)(param_1 + 0x114),0x12);
        *(undefined1 *)(param_1 + 0x55) = 9;
        bVar1 = *(byte *)(param_1 + 0xc);
      }
      bVar2 = *(byte *)(param_1 + 0x55);
      uVar5 = (uint)bVar2;
      iVar4 = uVar5 + 0x1a;
      if ((bVar1 & 4) == 0) {
        *(undefined4 *)(param_1 + iVar4 * 4) = 0xffffffff;
        *(undefined4 *)(param_1 + (uVar5 + 0x24) * 4) = 0xffffffff;
        *(undefined4 *)(param_1 + (uVar5 + 0x2e) * 4) = 0xffffffff;
        *(undefined4 *)(param_1 + (uVar5 + 0x38) * 4) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
        *(undefined4 *)(param_1 + 100) = 0xffffffff;
        *(undefined1 *)(param_1 + uVar5 + 0x108) = 0x7f;
        *(undefined2 *)(param_1 + (uVar5 + 0x88) * 2 + 2) = 0xffff;
      }
      else {
        uVar6 = *(uint *)(param_1 + 0x24);
        if (uVar6 == 0xffffffff) {
          *(undefined4 *)(param_1 + iVar4 * 4) = 0xffffffff;
        }
        else {
          uVar7 = uVar6 >> 3;
          if (uVar6 < 8) {
            uVar7 = (uint)(uVar6 != 0);
          }
          *(uint *)(param_1 + iVar4 * 4) = uVar7;
        }
        uVar6 = *(uint *)(param_1 + 0x28);
        if (uVar6 == 0xffffffff) {
          *(undefined4 *)(param_1 + (uVar5 + 0x24) * 4) = 0xffffffff;
        }
        else {
          uVar7 = uVar6 >> 3;
          if (uVar6 < 8) {
            uVar7 = (uint)(uVar6 != 0);
          }
          *(uint *)(param_1 + (uVar5 + 0x24) * 4) = uVar7;
        }
        *(undefined4 *)(param_1 + (uVar5 + 0x2e) * 4) = *(undefined4 *)(param_1 + 0x60);
        *(undefined4 *)(param_1 + (uVar5 + 0x38) * 4) = *(undefined4 *)(param_1 + 100);
        *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
        *(undefined4 *)(param_1 + 100) = 0xffffffff;
        *(undefined1 *)(param_1 + uVar5 + 0x108) = *(undefined1 *)(param_1 + 0xf);
        *(undefined2 *)(param_1 + (uVar5 + 0x88) * 2 + 2) = *(undefined2 *)(param_1 + 0x14);
        *(byte *)(param_1 + 0xc) = bVar1 & 0xfb;
      }
      *(undefined4 *)(param_1 + 0x5c) = uVar9;
      *(undefined4 *)(param_1 + 0x58) = uVar8;
      *(byte *)(param_1 + 0x55) = bVar2 + 1;
      return;
    }
    if (stats_warning_switch == '\0') {
      return;
    }
    __format = "[STATISTICS_WARNING]%s()/%d get ap entry by id failed.\n";
    uVar8 = 0x217;
  }
  printf(__format,"_stats_sta_sample_handle",uVar8);
  return;
}

