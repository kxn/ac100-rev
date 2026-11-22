// func _apdb_parse_rrst_bandwidth_from_apdb @ 005f9bd0 size=364

undefined4 _apdb_parse_rrst_bandwidth_from_apdb(char *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  size_t sVar3;
  undefined4 uVar4;
  uint uVar5;
  char local_28 [8];
  
  uVar4 = 0xffffffff;
  if (param_1 != (char *)0x0) {
    uVar5 = 0;
    bVar2 = false;
    bVar1 = false;
    do {
      if ((param_2 >> (uVar5 & 0x1f) & 1U) != 0) {
        if (bVar1) {
          sVar3 = strlen(param_1);
          if (199 < sVar3 + 1) break;
          strncat(param_1," ",200 - sVar3);
          if (uVar5 == 0) {
            bVar2 = true;
          }
          else {
LAB_005f9c30:
            sVar3 = strlen(param_1);
            if (199 < sVar3 + 1) break;
            local_28[0] = '\0';
            local_28[1] = '\0';
            snprintf(local_28,2,"%d",uVar5);
            sVar3 = strlen(param_1);
            strncat(param_1,local_28,200 - sVar3);
          }
        }
        else {
          if (uVar5 != 0) {
            bVar1 = true;
            goto LAB_005f9c30;
          }
          bVar2 = true;
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 6);
    uVar4 = 0;
    if ((bVar2) && (sVar3 = strlen(param_1), sVar3 + 2 < 200)) {
      strncat(param_1," 0",200 - sVar3);
    }
  }
  return uVar4;
}

