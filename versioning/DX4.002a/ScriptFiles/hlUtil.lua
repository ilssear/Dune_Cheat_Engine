

require("defines".."")




local function symLookup(sym)
  if sym:find("_org") then
    printf("SYM LOOKUP: \"%s\"", sym)
  end
  return nil
end

--[[
registerSymbolLookupCallback(function(string):integer, location): ID  6.4+
  Registers a function to be called when a a symbol is parsed
  Location determines at what part of the symbol lookup the function is called
    slStart: The very start of a symbol lookup. Before tokenization
    slNotInt: Called when it has been determined it's not a hexadecimal only string. Before tokenization
    --The following locations can be called multiple times for one string as they are called for each token and appended token
    slNotModule: Called when it has been determined the current token is not a modulename
    slNotUserdefinedSymbol: Called when it has been determined it's not a userdefined symbol
    slNotSymbol: Called when it has been determined it's not a symbol in the symbollist
    slFailure: Called when it has no clue what the given string is

    Note: slNotSymbol and slFailure are similar, but failure comes only if there's no token after the current token
          that can be concatenated. Else slNotSymbol will loop several times till all tokens make up the full string


  Return an Integer with the corresponding address if you found it. Nil or 0 if you didn't.

unregisterSymbolLookupCallback(ID): Removes the callback
--]]

if _G["_hlUtilSymLookupId"..""] then
  unregisterSymbolLookupCallback(_G["_hlUtilSymLookupId"..""])
end
_G._hlUtilSymLookupId = registerSymbolLookupCallback(symLookup, slNotSymbol)

