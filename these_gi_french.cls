% =========================================================================
% CLASSE LaTeX POUR LA REDACTION DE TH�SE
% 
% Julien Chiquet
%
% N�cessite au moins un fichier de style pour la th�se
% plus le fichier de style pour les pages administratives

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{these_gi_french}[2005/09/21 Classe pour ma th�se]

%% Les differents styles 
\newif\if@stylejchiquetfrench \@stylejchiquetfrenchfalse
% POUR L'INSTANT UN SEUL !!!

%% Chargement de la classe book, avec transfert d'options
\PassOptionsToClass{a4paper}{book}
\PassOptionsToClass{11pt}{book}
\PassOptionsToClass{twoside}{book}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{book}}
\DeclareOption{stylejchiquetfrench}{\@stylejchiquetfrenchtrue}
\DeclareOption*{}
\ProcessOptions
\LoadClass{book}

% ==========================================================================
% PACKAGES STANDARD REQUIS

% FONTS ET CARACT�RES
\RequirePackage[T1]{fontenc}
\RequirePackage[latin1]{inputenc}
\RequirePackage[frenchb]{babel}
\frenchspacing
\RequirePackage{eurosym}
\RequirePackage{xcolor}
% ============================================================================
% CHARGEMENT DE LA FEUILLE DE STYLE CHOISIE
\if@stylejchiquetfrench
  \RequirePackage{stylejchiquetfrench}
\fi
