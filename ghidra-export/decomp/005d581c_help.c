// func help @ 005d581c size=104

void help(void)

{
  int iVar1;
  
  for (iVar1 = FUN_004081b0(&udbg_help_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
    printf("%-32s  -- print help information for ** %s ** module \n\r",iVar1 + 0x6c,iVar1 + 0xc);
  }
  return;
}

