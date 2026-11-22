// func apupd_db_firmed_model_get @ 0065853c size=932

undefined4 apupd_db_firmed_model_get(int param_1,int param_2)

{
  int iVar1;
  undefined4 *__dest;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *__nptr;
  undefined4 uVar6;
  undefined4 local_228;
  undefined2 local_224;
  undefined2 local_222;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  char acStack_20c [128];
  undefined1 auStack_18c [132];
  undefined1 auStack_108 [86];
  char acStack_b2 [65];
  char local_71 [85];
  
  uVar6 = 0;
  memset(acStack_20c,0,0x80);
  memset(auStack_18c,0,0x168);
  local_220 = 0;
  local_21c = 0;
  local_218 = 0;
  local_214 = 0;
  local_210 = 0;
  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0x24) == 0)) {
    local_228 = *(undefined4 *)(param_1 + 0x40);
    local_224 = *(undefined2 *)(param_1 + 0x44);
    local_222 = *(undefined2 *)(param_1 + 0x46);
    memcpy(&local_220,(void *)(param_1 + 0x208),0x10);
    local_210 = CONCAT22(*(undefined2 *)(param_1 + 0x12),local_210._2_2_);
    iVar1 = FUN_00407fa0(*(undefined4 *)(param_2 + 0x14),&local_228);
    if (iVar1 == 0) {
      pcVar5 = *(char **)(param_2 + 0xc);
      if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {
        __nptr = *(char **)(param_2 + 0x10);
        iVar1 = strcmp(pcVar5,"is_online");
        if ((iVar1 == 0) && (uVar3 = atoi(__nptr), *(int *)(param_1 + 0x2ac) - 2U < 2 != uVar3)) {
          return 0;
        }
      }
      uVar6 = 1;
      __dest = (undefined4 *)FUN_00408450(0x1c,0x279d);
      if (__dest != (undefined4 *)0x0) {
        memcpy(__dest,&local_228,0x1c);
        iVar1 = FUN_00408380(*(undefined4 *)(param_2 + 0x14),__dest);
        if (iVar1 == 0) {
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
          iVar1 = json_object_new_object();
          if (iVar1 == 0) {
            if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              printf("[APUPD_ERROR]%32s() %05d: Create json object failed when get ap_upd model.\r\n"
                     ,"apupd_db_firmed_model_get",0x27ae);
            }
          }
          else {
            iVar2 = apdb_get_ap_by_id(*__dest,param_1 + 0x218,auStack_18c);
            if (iVar2 == 0) {
              pcVar5 = local_71;
              if (local_71[0] == '\0') {
                pcVar5 = acStack_b2;
              }
              uVar6 = json_object_new_string(pcVar5);
              json_object_object_add(iVar1,"model_name",uVar6);
              snprintf(acStack_20c,0x80,"%d",*__dest);
              uVar6 = json_object_new_string(acStack_20c);
              json_object_object_add(iVar1,"model_id",uVar6);
            }
            snprintf(acStack_20c,0x80,"%u.%u",(uint)*(ushort *)(__dest + 1),
                     (uint)*(ushort *)((int)__dest + 6));
            uVar6 = json_object_new_string(acStack_20c);
            json_object_object_add(iVar1,"hardware_ver",uVar6);
            uVar3 = __dest[4];
            sprintf(acStack_20c,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)*(ushort *)(__dest + 2)
                    ,(uint)*(ushort *)((int)__dest + 10),(uint)*(ushort *)(__dest + 3),uVar3 >> 0x10
                    ,(uVar3 << 0x10) >> 0x18,uVar3 & 0xff,__dest[5]);
            uVar6 = json_object_new_string(acStack_20c);
            json_object_object_add(iVar1,"software_ver",uVar6);
            snprintf(acStack_20c,0x80,"%d",(uint)*(ushort *)(param_1 + 0x12));
            uVar6 = 0;
            uVar4 = json_object_new_string(acStack_20c);
            json_object_object_add(iVar1,"group_id",uVar4);
            strncpy(acStack_20c,"",0x80);
            FUN_004084f0(param_1 + 0x218,0x10,acStack_20c);
            uVar4 = json_object_new_string(acStack_20c);
            json_object_object_add(iVar1,"firmware_id",uVar4);
            strncpy(acStack_20c,"",0x80);
            FUN_004084f0(auStack_108,0x10,acStack_20c);
            uVar4 = json_object_new_string(acStack_20c);
            json_object_object_add(iVar1,"hardware_id",uVar4);
            json_object_array_add(*(undefined4 *)(param_2 + 0x18),iVar1);
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

