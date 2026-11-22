// func print_item @ 0060dfdc size=208

void print_item(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  while (iVar3 < l_apdb_ap_item_cnt_cur) {
    iVar1 = iVar3 * 0x58;
    if (apdb_debug_switch == 0) {
      iVar3 = iVar3 + 1;
    }
    else {
      iVar3 = iVar3 + 1;
      puVar2 = (undefined4 *)(l_apdb_ap_item_cur + iVar1);
      printf("[APDB_DEBUG]%s()/line %d : id:%d,name:%s,ap_cnt:%d,vendor:%d\n\n","print_item",0x3053,
             *puVar2,puVar2 + 2,puVar2[0x13],puVar2[1]);
    }
  }
  return;
}

