#! bash 

# build docs with doxygen, generates ./docs/xml folder
doxygen ./docs/doxyfile

mkdir -p docs/doxybook2

# generate markdown file with doxybook2
doxybook2 -i ./docs/xml -o docs/doxybook2 -c ./docs/doxybook2_config.json --templates ./docs/doxybook2-templates

# The generated file is now in docs/doxybook2/Classes/class_f_analytics_provider_treasure_data.md
cp ./docs/doxybook2/Classes/class_f_analytics_provider_treasure_data.md ./docs/api.md
