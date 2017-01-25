"http://vim.wikia.com/wiki/C%2B%2B_code_completion
set nocompatible "run in vim mode
set autoindent "auto-indent new lines
set smartindent "return ending brackets to proper locations
set softtabstop=4 "indentation level of soft-tabs
set tabstop=4 "indentation leves of normal tabs
set shiftwidth=4 "how many columns to re-indent with << and >>
set showmatch "show matching brackets
set ruler "show cursor position at all times
set nohls "don't highlight the previous search term
set wrap "turn on visual word wrapping
set linebreak "only break lines on 'breakat' characters

if has("autocmd")
au BufReadPost * if line("'\"") > 0 && line("'\"") <= line("$")
\| exe "normal g'\"" | endif
endif
augroup filetypedetect
au BufNewFile,BufRead *.tcc set filetype=cpp
au! BufRead,BufNewFile *nc setfiletype nc "http://www.vim.org/scripts/script.php?script_id=1847
"html.ep now handled by https://github.com/yko/mojo.vim
augroup END 

:set bs=2 "fix backspace on some consoles
syntax on
:set autoindent
:set cindent
:set shiftwidth=4
:set expandtab
:set hlsearch
:set incsearch
:set showmatch
colorscheme desert
:set ai "Auto indent
:set si "Smart indent
:set wrap "Wrap lines
:set ic
:set paste
:set tags=./tags;
syntax on
highlight Comment cterm=underline ctermbg=Black ctermfg=White
au BufNewFile,BufRead,BufEnter *.cpp,*.hpp,*.tcc,*.h set omnifunc=omni#cpp#complete#Main
set nocp
filetype plugin on
set tags+=~/.vim/tags/cpp
map <C-F12> :!ctags -R --sort=yes --c++-kinds=+pl --fields=+iaS --extra=+q .<CR>
let OmniCpp_NamespaceSearch = 1
let OmniCpp_GlobalScopeSearch = 1
let OmniCpp_ShowAccess = 1
let OmniCpp_ShowPrototypeInAbbr = 1 " show function parameters
let OmniCpp_MayCompleteDot = 1 " autocomplete after .
let OmniCpp_MayCompleteArrow = 1 " autocomplete after ->
let OmniCpp_MayCompleteScope = 1 " autocomplete after ::
let OmniCpp_DefaultNamespaces = ["std", "_GLIBCXX_STD"]
" automatically open and close the popup menu / preview window
au CursorMovedI,InsertLeave * if pumvisible() == 0|silent! pclose|endif
set completeopt=menuone,menu,longest,preview
