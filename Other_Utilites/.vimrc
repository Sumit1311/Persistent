

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

:set tags=$MERC/tags;

syntax on

highlight Comment cterm=underline ctermbg=Black ctermfg=White

