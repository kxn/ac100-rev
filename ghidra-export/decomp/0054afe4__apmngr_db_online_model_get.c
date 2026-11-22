// func _apmngr_db_online_model_get @ 0054afe4 size=736

undefined4 _apmngr_db_online_model_get(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *__dest;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_218;
  undefined2 local_214;
  undefined2 local_212;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  char acStack_200 [128];
  undefined1 auStack_180 [218];
  char acStack_a6 [65];
  char local_65 [81];
  
  uVar5 = 0;
  memset(acStack_200,0,0x80);
  memset(auStack_180,0,0x168);
  local_210 = 0;
  local_20c = 0;
  local_208 = 0;
  local_204 = 0;
  uVar6 = uVar5;
  if ((((*(int *)(param_1 + 0x3c) == param_2[7]) && (*(int *)(param_1 + 0xc) != 0)) &&
      (uVar6 = 0, *(int *)(param_1 + 0x2ac) - 2U < 2)) && (uVar6 = 0, *(int *)(param_1 + 0x24) == 0)
     ) {
    local_218 = *(undefined4 *)(param_1 + 0x40);
    local_214 = *(undefined2 *)(param_1 + 0x44);
    local_212 = *(undefined2 *)(param_1 + 0x46);
    memcpy(&local_210,(void *)(param_1 + 0x208),0x10);
    iVar1 = FUN_00407fa0(param_2[5],&local_218);
    uVar6 = uVar5;
    if ((iVar1 == 0) &&
       (((pcVar4 = (char *)param_2[3], pcVar4 == (char *)0x0 || (*pcVar4 == '\0')) ||
        (iVar1 = _apmngr_db_search_check(param_1,pcVar4,param_2[4]), iVar1 == 1)))) {
      uVar6 = 1;
      __dest = (undefined4 *)FUN_00408450(0x18,0x870);
      if (__dest != (undefined4 *)0x0) {
        memcpy(__dest,&local_218,0x18);
        iVar1 = FUN_00408380(param_2[5],__dest);
        if (iVar1 == 0) {
          param_2[2] = param_2[2] + 1;
          if (*param_2 < 1) {
            uVar6 = 0;
            if (0 < param_2[1]) {
              iVar1 = json_object_new_object();
              if (iVar1 == 0) {
                uVar6 = 1;
                if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                  printf("[APMNGR_ERROR]%s()/%d Create json object failed when tranverse ap online model list.\n"
                         ,"_apmngr_db_online_model_get",0x88a);
                }
              }
              else {
                iVar2 = apdb_get_ap_by_id(*__dest,param_1 + 0x218,auStack_180);
                if (iVar2 == 0) {
                  pcVar4 = local_65;
                  if (local_65[0] == '\0') {
                    pcVar4 = acStack_a6;
                  }
                  uVar6 = json_object_new_string(pcVar4);
                  json_object_object_add(iVar1,"model_name",uVar6);
                }
                snprintf(acStack_200,0x80,"%u.%u",(uint)*(ushort *)(__dest + 1),
                         (uint)*(ushort *)((int)__dest + 6));
                uVar6 = json_object_new_string(acStack_200);
                json_object_object_add(iVar1,"hardware_ver",uVar6);
                uVar3 = __dest[4];
                sprintf(acStack_200,"%d.%d.%d Build %02d%02d%02d Rel.%05d",
                        (uint)*(ushort *)(__dest + 2),(uint)*(ushort *)((int)__dest + 10),
                        (uint)*(ushort *)(__dest + 3),uVar3 >> 0x10,(uVar3 << 0x10) >> 0x18,
                        uVar3 & 0xff,__dest[5]);
                uVar6 = json_object_new_string(acStack_200);
                json_object_object_add(iVar1,"software_ver",uVar6);
                uVar6 = 0;
                json_object_array_add(param_2[6],iVar1);
                param_2[1] = param_2[1] + -1;
              }
            }
          }
          else {
            uVar6 = 0;
            *param_2 = *param_2 + -1;
          }
        }
        else {
          FUN_00407df0(__dest);
        }
      }
    }
  }
  return uVar6;
}

