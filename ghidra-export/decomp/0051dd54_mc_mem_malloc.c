// func mc_mem_malloc @ 0051dd54 size=44

void mc_mem_malloc(void)

{
  mckernelVmManageMalloc();
  return;
}

