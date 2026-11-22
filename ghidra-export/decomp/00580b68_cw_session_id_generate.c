// func cw_session_id_generate @ 00580b68 size=1

/* WARNING: Removing unreachable block (ram,0x00580ba0) */

void cw_session_id_generate(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 0;
    do {
      iVar1 = rand();
      puVar2 = (undefined1 *)(param_1 + iVar3);
      iVar3 = iVar3 + 1;
      *puVar2 = (char)(iVar1 % 0x100);
    } while (iVar3 != 0x10);
  }
  return;
}

