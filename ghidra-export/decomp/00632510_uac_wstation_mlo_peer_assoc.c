// func uac_wstation_mlo_peer_assoc @ 00632510 size=500

int uac_wstation_mlo_peer_assoc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined1 local_84;
  undefined1 local_83;
  undefined1 auStack_7a [7];
  undefined1 local_73;
  undefined1 auStack_40 [24];
  
  iVar6 = -1;
  memset(auStack_a8,0,0x80);
  if (param_1 != (undefined4 *)0x0) {
    local_b0 = 1;
    local_ac = 1;
    puVar4 = param_1;
    for (iVar5 = 0; iVar5 < (int)(uint)*(byte *)((int)param_1 + 0x12); iVar5 = iVar5 + 1) {
      memset(auStack_a8,0,0x80);
      uVar7 = *param_1;
      uVar1 = *(undefined1 *)(puVar4 + 5);
      uVar2 = *(undefined1 *)((int)puVar4 + 0x15);
      local_73 = (undefined1)puVar4[7];
      local_88 = uVar7;
      local_84 = uVar1;
      local_83 = uVar2;
      memcpy(auStack_40,(void *)((int)puVar4 + 0x16),6);
      iVar3 = memcmp(param_1 + 3,(void *)((int)param_1 + iVar5 * 0xc + 0x16),6);
      if (iVar3 == 0) {
        local_b0 = 0;
      }
      iVar3 = uac_wservice_get_vlan(uVar7,uVar1,uVar2,auStack_7a);
      if (iVar3 != 0) {
        if (g_wsta_error == 0) {
          return iVar6;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return iVar6;
        }
        printf("<wsta>[error]%s(): %d  -> uac_wservice_get_vlan() fail\r\n",
               "uac_wstation_mlo_peer_assoc",0x548);
        return iVar6;
      }
      iVar6 = wsta_db_sta_assoc(auStack_a8,0,_uac_wsta_implicit_del_cb,0,param_2,param_3,&local_b0);
      if ((iVar6 != 0) && (iVar6 != 2)) {
        if (g_wsta_debug == 0) {
          return iVar6;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return iVar6;
        }
        printf("<wsta>[debug]%s(): %d  -> peer%d assoc failed\r\n","uac_wstation_mlo_peer_assoc",
               0x54f,iVar5 + 1);
        return iVar6;
      }
      puVar4 = puVar4 + 3;
    }
  }
  return iVar6;
}

