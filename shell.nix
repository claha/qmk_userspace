{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "qmk-dev";

  buildInputs = with pkgs; [
    qmk
  ];
}
