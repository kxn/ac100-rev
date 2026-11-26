// @category ACAP
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.*;

public class ImportVendorSymbols extends GhidraScript {
 public void run() throws Exception {
  int count=0;
  for(String line:Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
   String[] parts=line.trim().split("\\s+",4);
   if(parts.length!=4)continue;
   Address at=toAddr(Long.parseUnsignedLong(parts[0],16));
   if(!currentProgram.getMemory().contains(at))continue;
   try {createLabel(at,parts[3].replaceAll("[^A-Za-z0-9_$._]","_"),true);count++;} catch(Exception e){}
  }
  println("Vendor labels imported: "+count);
 }
}
