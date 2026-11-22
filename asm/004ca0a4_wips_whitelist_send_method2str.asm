; func wips_whitelist_send_method2str @ 0x004ca0a4 size=0x44
  4ca0a4:	1080000a 	beqz	a0,0x4ca0d0
  4ca0a8:	3c02006a 	lui	v0,0x6a
  4ca0ac:	24020001 	li	v0,1
  4ca0b0:	10820009 	beq	a0,v0,0x4ca0d8
  4ca0b4:	3c02006a 	lui	v0,0x6a
  4ca0b8:	24020002 	li	v0,2
  4ca0bc:	50820008 	beql	a0,v0,0x4ca0e0
  4ca0c0:	3c02006a 	lui	v0,0x6a
  4ca0c4:	3c020069 	lui	v0,0x69
  4ca0c8:	03e00008 	jr	ra
  4ca0cc:	24428af8 	addiu	v0,v0,-29960
  4ca0d0:	03e00008 	jr	ra
  4ca0d4:	244272a0 	addiu	v0,v0,29344
  4ca0d8:	03e00008 	jr	ra
  4ca0dc:	24427000 	addiu	v0,v0,28672
  4ca0e0:	03e00008 	jr	ra
  4ca0e4:	244272b0 	addiu	v0,v0,29360
